### Persistent & Sequential Server

> tldr;
> 
> Sequential server will create a new socket for every incoming connection.
> 
> Persistent server will handle requests on the same socket by creating new threads.

<br>

HTTP persistent connection, also called `HTTP keep-alive`, or `HTTP connection reuse`, is the idea of using a single TCP
connection to send and receive multiple HTTP requests/responses, as opposed to opening a new connection for every single
request/response pair. The newer HTTP/2 protocol uses the same idea and takes it further to allow multiple concurrent
requests/responses to be multiplexed over a single connection.

<hr>

See also: [wikipedia.org/wiki/HTTP_persistent_connection](https://en.wikipedia.org/wiki/HTTP_persistent_connection)