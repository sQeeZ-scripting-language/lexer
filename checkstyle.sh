#!/bin/bash

function run_clang_format {
  local file=$1
  local result=$(clang-format -style=file -output-replacements-xml "$file")
  local replacements=$(echo "$result" | grep -o "<replacement " | wc -l)
  if [ "$replacements" -ne 0 ]; then
    echo "Code style issues found in file: $file"
    clang-format -style=file "$file" | diff "$file" - | colordiff
    echo "Number of replacements: $replacements"
  fi
}

echo "Running clang-format..."
clang_format_failed=0
for file in $(find . -name '*.cpp' -o -name '*.h'); do
  if ! run_clang_format "$file"; then
    clang_format_failed=1
  fi
done

echo "Running cpplint..."
cpplint_failed=0
cpplint_output=$(mktemp)
cpplint $(find . -name '*.cpp' -o -name '*.h') 2>&1 | tee "$cpplint_output"
if [[ ${PIPESTATUS[0]} -ne 0 ]]; then
  cpplint_failed=1
fi

if [[ $clang_format_failed -ne 0 ]]; then
  echo "clang-format check failed."
fi

if [[ $cpplint_failed -ne 0 ]]; then
  echo "cpplint check failed."
fi

if [[ $clang_format_failed -ne 0 || $cpplint_failed -ne 0 ]]; then
  exit 1
else
  echo "All checks passed!"
fi
