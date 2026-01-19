import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # GET route
    if request.method == "GET":
        user_rows = db.execute(
            "SELECT cash FROM users WHERE id = ?",
            session["user_id"]
        )
        cash = float(user_rows[0]["cash"])
        return render_template("buy.html", usd=usd, cash=cash)

    # POST route
    if request.method == "POST":

        # Validate stock `symbol` form field
        symbol = request.form.get("symbol")
        if len(symbol) == 0:
            return apology("Stock symbol cannot be blank")

        stock = lookup(symbol)
        if not stock:
            return apology(f"Stock symbol '{symbol}' does not exist")

        # Validate stock `shares` form field
        shares = request.form.get("shares")
        if not shares or not shares.isdigit():
            return apology("Invalid share amount")

        shares = int(shares)
        if shares < 1:
            return apology("Must buy at least 1 share")

        # Stop transaction if user has insufficient funds
        user_rows = db.execute(
            "SELECT cash FROM users WHERE id = ?",
            int(session["user_id"])
        )
        cash = float(user_rows[0]["cash"])
        total_price = stock["price"] * shares
        if total_price > cash:
            return apology(
                f"Insufficient cash ({usd(cash)}) for buying {shares} share(s) of '{symbol}' at {usd(stock['price'])} per share"
            )

        # Complete the buy transaction
        db.execute(
            "UPDATE users SET cash = (cash - ?) WHERE id = ?",
            total_price,
            int(session["user_id"])
        )

        db.execute(
            """
            INSERT INTO user_transactions(
                user_id, action, stock_symbol, shares
            )
            VALUES(?, 'buy', ?, ?);
            """,
            int(session["user_id"]),
            symbol,
            shares
        )       

        return redirect("/")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # GET route
    if request.method == "GET":
        return render_template("quote.html")

    # POST route
    if request.method == "POST":

        # Validate `symbol` field
        symbol = request.form.get("symbol")

        if len(symbol) == 0:
            return apology("Stock symbol cannot be blank")

        stock = lookup(symbol)
        if not stock:
            return apology(f"Stock symbol '{stock}' does not exist")

        return render_template("quoted.html", stock=stock, usd=usd)

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    # GET route
    if request.method == "GET":
        return render_template("register.html")

    # POST route
    if request.method == "POST":

        # Validate `username` field
        username = request.form.get("username")

        if len(username) == 0:
            return apology("Username cannot be blank")

        rows = db.execute("SELECT COUNT(*) FROM users WHERE username = ?", username)
        if int(rows[0]["COUNT(*)"]) > 0:
            return apology("Username already exists")

        # Validate `password` and `confirmation` fields
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if len(password) == 0 or len(confirmation) == 0:
            return apology("Password or confirmed password cannot be blank")

        if password != confirmation:
            return apology("Confirmed password does not match password")

        # Add new user to database
        password_hash = generate_password_hash(password)
        try:
            res = db.execute(
                "INSERT INTO users (username, hash) VALUES(?, ?)",
                username, password_hash
            )
        except ValueError as e:
            return apology("Username already exists or error adding user")

        # Redirect user to home page
        return redirect("/")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
