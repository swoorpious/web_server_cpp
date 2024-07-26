### Persistent & Sequential Server

[HTTP](https://en.wikipedia.org/wiki/HTTP) persistent connection, also called `HTTP keep-alive`, or `HTTP connection reuse`, is the idea of using a single [TCP](https://en.wikipedia.org/wiki/Transmission_Control_Protocol)
connection to send and receive multiple [HTTP requests](https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol)/responses, as opposed to opening a new connection for every single
request/response pair.

The newer [HTTP/2](https://en.wikipedia.org/wiki/HTTP/2) protocol uses the same idea and takes it further to allow multiple concurrent
requests/responses to be multiplexed over a single connection.

<hr>

See also: [wikipedia.org/wiki/HTTP_persistent_connection](https://en.wikipedia.org/wiki/HTTP_persistent_connection)