# Week 9 Flask

## Lecture Material

- web page: https://cs50.harvard.edu/x/weeks/9
- notes: https://cs50.harvard.edu/x/notes/9/
- slides: https://cdn.cs50.net/cs50/fall/lectures/9/lecture9.pdf
- code: https://cdn.cs50.net/cs50/fall/lectures/9/src9/
- Problem Set 9: https://cs50.harvard.edu/x/psets/9/
- topics:
    - Flask. Route. Decorators. Requests, Responses. Sessions. Cookies.

## Notes

- video timestamp: 56:05
- Flask: a Python web server micro-framework 
- basics
    ```
    flask run
    ```
- needed files and optional ones
    ```
    app.py
    requirements.txt
    templates/
    ```
- boilerplate code:
    ```python
    from flask import Flask

    app = Flask(__name__)

    @app.route("/")
    def index():
        return "hello, world"
    ```
- misc:
    ```
    request.args
    ```
- Jinja: a Python dynamic HTML templating library
    - used internally by Flask
    - jinja.palletsprojects.com/templates/

## Problem Set 9

- [ ] Complete [Birthdays](https://cs50.harvard.edu/x/psets/9/birthdays/)
- [ ] Complete [Finance](https://cs50.harvard.edu/x/psets/9/finance/)
