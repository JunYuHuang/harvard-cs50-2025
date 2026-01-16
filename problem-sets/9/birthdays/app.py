import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

# Constants
MIN_MONTH = 1
MAX_MONTH = 12
MIN_DAY = 1
MAX_DAY = 31

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database

        # Validate name
        name = request.form.get("name")
        if not name:
            print(">>>> Bad name")
            return redirect("/")

        # Validate month
        month = int(request.form.get("month"))
        if month < MIN_MONTH or month > MAX_MONTH:
            print(">>>> Bad month")
            return redirect("/")

        # Validate day
        day = int(request.form.get("day"))
        if day < MIN_DAY or day > MAX_DAY:
            print(">>>> Bad day")
            return redirect("/")

        # Save birthday
        db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", name, month, day)

        # Re-render the page
        return redirect("/")
    else:

        # TODO: Display the entries in the database on index.html
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)


