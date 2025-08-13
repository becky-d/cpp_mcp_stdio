# cpp_mcp_stdio
MCP protocol analysis
### The id of the MCP protocol read also needs to be the same when writing
stdio works through process input and output
stdread && stdwrite

### Handshake protocol 1 initializes, client input, must end on behalf of '\n'
    {"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2024-11-05","capabilities":{},"clientInfo":{"name":"demo-cli","version":"1.0"}}}
### Handshake protocol 2, server return
    {"jsonrpc":"2.0","id":0,"result":{"protocolVersion":"2024-11-05","capabilities":{"prompts":{"listChanged":false},"resources":{"subscribe":false,"listChanged":false},"tools":{"listChanged":false}},"serverInfo":{"name":"Cangjie Magic Agent Server","version":"0.1"}}}
### Handshake Protocol 3 client sends, The service does not need to return
    {"jsonrpc":"2.0","method":"notifications/initialized"}

### Formal correspondence: 1.Query tools/list and fix the command
    {"jsonrpc":"2.0","id":2,"method":"tools/list","params":{}}
### response
    {"jsonrpc":"2.0","id":2,"result":{"tools":[{"name":"add","description":"Add two numbers","inputSchema":{"type":"object","properties":{"a":{"type":"integer"},"b":{"type":"integer"}},"required":["a","b"]}},{"name":"multiply","description":"Multiply two numbers","inputSchema":{"type":"object","properties":{"a":{"type":"integer"},"b":{"type":"integer"}},"required":["a","b"]}},{"name":"Calculator","description":"小学算术计算器","inputSchema":{"type":"object","properties":{"question":{"type":"string","description":"The input question"}},"required":["question"]}}]}}

### Heartbeat test, The service does not need to return
{"jsonrpc":"2.0","method":"ping","id":"0acb05c1-2"}





Full Story:
### One: init
{"jsonrpc":"2.0","id":"9c0d0aee204640eaacdb13f531689279-1","method":"initialize","params":{"protocolVersion":"2024-11-05","capabilities":{},"clientInfo":{"name":"Email.MCPClient","version":"1.0.0.0"}}}
{"id":"9c0d0aee204640eaacdb13f531689279-1","jsonrpc":"2.0","result":{"capabilities":{"tools":{"listChanged":false}},"protocolVersion":"2024-11-05","serverInfo":{"name":"hello_server","version":"1.0.0.1"}}}
{"jsonrpc":"2.0","method":"notifications/initialized"}


### Two: tools/list
{"jsonrpc":"2.0","id":"9c0d0aee204640eaacdb13f531689279-2","method":"tools/list","params":{}}
{"id":"9c0d0aee204640eaacdb13f531689279-2","jsonrpc":"2.0","result":{"tools":[{"description":"Receive the data sent by the client and then return the exact same data to the client.","inputSchema":{"properties":{"input":{"description":"client input data","type":"string"}},"required":["input"],"type":"object"},"name":"hello"}]}}

### Three: tools/call

{"jsonrpc":"2.0","id":"7b6d33b88e714c2c87975aa2625529a6-2","method":"tools/call","params":{"name":"hello","arguments":{"name":"sInput"}}}
{"jsonrpc":"2.0","id":"0ddb452e8c824894960130aa4d24cb54-2","result":{"isError":false,"content":[{"type":"text","text":"Hello, sInput!"}]}}


