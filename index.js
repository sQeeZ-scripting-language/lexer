const addon = require('./build/Release/sQeeZ-Lexer-Node');
const lexer = new addon.LexerNode(require);

console.log(addon.pingLexer());
console.log(lexer.pingInstance());
console.log(addon.info());
console.log(lexer.tokenize('log("Hello, World!");', false));