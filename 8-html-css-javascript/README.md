# Week 8 HTML, CSS, JavaScript

## Lecture Material

- web page: https://cs50.harvard.edu/x/weeks/cs50cs50/
- notes: https://cs50.harvard.edu/x/notes/8/
- slides: https://cdn.cs50.net/8088/fall/lectures/8/lecture8.pdf
- code: https://cdn.cs50.net/8088/fall/lectures/8/src8/
- Problem Set 8: https://cs50.harvard.edu/x/psets/8/
- topics:
    - Internet: Routers; TCP/IP; DNS. HTTP: URLs, GET, POST. HTML: Tags; Attributes. Servers. Regular Expressions. CSS: Properties; Selectors. Frameworks. JavaScript: Variables; Conditionals; Loops. Events.

## Notes

- internet
- routers
- TCP/IP: language / protocol for how computers talk to each other in the internet or in networks
    - 2 different protocols
    - IP = Internet Protocol
        - gives unique addresses
        - IPv4
            - format: #.#.#.#
            - each `#` can store up to 8 bits
        - IPv6
            - a
    - Example Internet Datagram Header (diagram)
    - servers
    - clients
    - TCP = Transmission Control Protocol
        - uniquely identifies services
        - guarantees reliable delivery of packets
- ports = numbers that are associated to services
    - 80 = HTTP
    - 443 = HTTPS
    - adds additional fields to the Internet Datagram Header
- DNS = Domain Name System
    - server that translates domain names into IP addresses
    - domain names = Fully Qualified Domain Name (FQDN)
- DHCP = Dynamic Host Control Protocol
    - server answers a client computer's question "What is my IP address?"
    - auto-assigns IP addresses to devices in a network
- HTTP = HyperText Transfer Protocol
    - gets and sends web pages
    - e.g. a canonical URL `https://www.example.com/path`
        - `/` = root (i.e., default directory) of website
        - `/path`
        - `www.example.com` = domain name; Fully Qualified Domain Name (FQDN)
        - `example.com` = domain name
        - `.com` = top level domain (TLD)
        - `www` = hostname; name of the server
        - `https` = scheme or protocol of service used
        - `/path?key=value` = key-value pairs
            - for passing input to a webpage
    - HTTP operations / verbs:
        - GET
        - POST
    - HTTP status codes and meanings
        ```
        200 OK
        301 Moved Permanently
        302 Found
        304 Not Modifie
        307 Temporary Redirect
        401 Unauthorized
        403 Forbidden
        404 Not Found
        418 I'm a Teapot
        500 Internal Server Error
        503 Service Unavailable
        ```
- curl: a headless CLI web browser application
- HTML = HyperText Markup Language
    - non-programming, markup language that tells a web browser what to show
    - web pages get sent as a copy
    - tags
    - attributes
    - HTML5 webpage boilerplate
        ```HTML
        <!DOCTYPE html>
        <html lang="en">
            <head>
                <title>
                    hello, title
                </title>
            </head>
            <body>
                hello, world
            </body>
        </html>
        ```
    - http-server: CLI tool to serve up a web page
    - opening and closing tags
    - a HTML document is an n-ary node tree
    - self-closing tags
- regular expressions; regexes
    - example syntax
        ```
        .       any single character (except line terminators)
        *       zero or more times
        +       one or more times
        ?       0 or 1 time
        {n}     n occurrences
        {n, m}  at least n occurrences, at most m occurrences
        
        [0123456789]    any one of the enclosed characters
        [0-9]           any one of the range of characters
        \d              any digit
        \D              any character that is not a digit
        ...
        ```
- don't trust user input
- HTML validator website
- CSS = Cascading StyleSheets
    - like the skin of a webpage
    - properties = key-value pairs in CSS
        ```
        type selector
        class selector
        ID selector
        attribute selector
        ...
        ```
    - apply in many ways
        - use `<style>` tag
        - link a stylesheet
- frameworks: way to do something with a library
    - E.g., Bootstrap: getbootstrap.com
- JavaScript: a programming language for client-side web development
    - core concepts and syntax
        - conditionals
        - variables
        - loops
    - typically put the JS part of a HTML web page at the bottom
    - web document events
        ```
        blur
        change
        click
        drag
        focus
        keyup
        load
        mousedown
        mouseover
        mouseup
        submit
        touchmove
        unload
        ...
        ```
    - camelCase

## Problem Set 8

- [ ] Complete [Trivia](https://cs50.harvard.edu/x/psets/8/trivia/)
- [ ] Complete [Homepage](https://cs50.harvard.edu/x/psets/8/homepage/)
