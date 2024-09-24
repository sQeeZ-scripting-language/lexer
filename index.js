const addon = require('./build/Release/sQeeZLexerNode');
const lexer = new addon.LexerNode(require);

console.log(addon.pingLexer());
console.log(lexer.pingInstance());