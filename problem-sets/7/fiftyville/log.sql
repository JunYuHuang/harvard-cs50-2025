-- Keep a log of any SQL queries you execute as you solve the mystery.

-- check what rows in the `crime_scene_reports` table look like:
SELECT * FROM crime_scene_reports LIMIT 3;
/*
Result:
         id = 1
       year = 2025
      month = 1
        day = 1
     street = Chamberlin Street
description = Credit card fraud took place at 00:53. Two people witnessed the event.

         id = 2
       year = 2025
      month = 1
        day = 1
     street = Zlatkova Street
description = Burglary took place at 05:23. Two people witnessed the event.

         id = 3
       year = 2025
      month = 1
        day = 1
     street = Bowden Boulevard
description = Shoplifting took place at 20:48. Two people witnessed the event.
*/


-- count records that match the theft whereabouts in the `crime_scene_reports` table:
SELECT COUNT(*) FROM crime_scene_reports
WHERE (
    month = 7 AND
    day = 28 AND
    year = 2025 AND
    street = 'Humphrey Street'
);
/*
Result:
+----------+
| COUNT(*) |
+----------+
| 2        |
+----------+
*/


-- review records' descriptions that match the theft whereabouts in the `crime_scene_reports` table:
SELECT description FROM crime_scene_reports
WHERE (
    month = 7 AND
    day = 28 AND
    year = 2025 AND
    street = 'Humphrey Street'
);
/*
Result:
description = Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

description = Littering took place at 16:36. No known witnesses.
*/


-- count matching interviews of the theft event
SELECT COUNT(*) FROM interviews
WHERE (
    month = 7 AND
    day = 28 AND
    year = 2025
);
/*
Result:
COUNT(*) = 7
*/


-- review matching interview of the theft event
SELECT transcript FROM interviews
WHERE (
    month = 7 AND
    day = 28 AND
    year = 2025
);
/*
Result:
transcript = “Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”

transcript = “I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”

transcript = “You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.

transcript = Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.     

transcript = I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

transcript = As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

transcript = Our neighboring courthouse has a very annoying rooster that crows loudly at 6am every day. My sons Robert and Patrick took the rooster to a city far, far away, so it may never bother us again. My sons have successfully arrived in Paris.
*/


-- check the earliest flight on July 29th:
SELECT * FROM flights
WHERE (
    month = 7 AND
    day = 29 AND
    year = 2025
)
ORDER BY hour, minute ASC
LIMIT 1;
/*
Result:
                    id = 36
     origin_airport_id = 8
destination_airport_id = 4
                  year = 2025
                 month = 7
                   day = 29
                  hour = 8
                minute = 20
*/


-- find the destination airport (i.e., city) that the thief's flight is headed towards:
SELECT city FROM airports
WHERE airports.id = 4;
/*
Result:
 city = New York City
*/


-- count passengers on the flight that the thief boarded:
SELECT COUNT(*) FROM passengers
WHERE passengers.flight_id = 36;
/*
Result:
COUNT(*) = 8
*/

-- review people who were on the flight that the thief boarded:
SELECT * FROM people
WHERE passport_number IN (
    SELECT passport_number FROM passengers
    WHERE passengers.flight_id = 36
);
/*
Result:
             id = 395717
           name = Kenny
   phone_number = (826) 555-1652
passport_number = 9878712108
  license_plate = 30G67EN

             id = 398010
           name = Sofia
   phone_number = (130) 555-0289
passport_number = 1695452385
  license_plate = G412CB7

             id = 449774
           name = Taylor
   phone_number = (286) 555-6063
passport_number = 1988161715
  license_plate = 1106N58

             id = 467400
           name = Luca
   phone_number = (389) 555-5198
passport_number = 8496433585
  license_plate = 4328GD8

             id = 560886
           name = Kelsey
   phone_number = (499) 555-9472
passport_number = 8294398571
  license_plate = 0NTHK55

             id = 651714
           name = Edward
   phone_number = (328) 555-1152
passport_number = 1540955065
  license_plate = 130LD9Z

             id = 686048
           name = Bruce
   phone_number = (367) 555-5533
passport_number = 5773159633
  license_plate = 94KL13X

             id = 953679
           name = Doris
   phone_number = (066) 555-9701
passport_number = 7214083635
  license_plate = M51FA04
*/


-- check how the records in the `bakery_security_logs` table look:
SELECT * FROM bakery_security_logs LIMIT 2;

/*
Result:
           id = 1
         year = 2025
        month = 7
          day = 25
         hour = 7
       minute = 1
     activity = entrance
license_plate = 0R0FW39

           id = 2
         year = 2025
        month = 7
          day = 25
         hour = 7
       minute = 31
     activity = entrance
license_plate = 97O6H62
*/


-- count logs that match the theft timeframe in the `bakery_security_logs` table:
SELECT COUNT(*) FROM bakery_security_logs
WHERE (
    month = 7 AND
    day = 28 AND
    year = 2025 AND
    (minute BETWEEN 15 AND 25)
);
/*
Result:
COUNT(*) = 25
*/

-- review logs that match the theft timeframe in the `bakery_security_logs` table:
SELECT activity, license_plate FROM bakery_security_logs
WHERE (
    month = 7 AND
    day = 28 AND
    year = 2025 AND
    (minute BETWEEN 15 AND 25)
);
/*
Result:
     activity = entrance
license_plate = D965M59

     activity = entrance
license_plate = HW0488P

     activity = exit
license_plate = D965M59

     activity = exit
license_plate = HW0488P

     activity = entrance
license_plate = L93JTIZ

     activity = entrance
license_plate = 94KL13X

     activity = entrance
license_plate = L68E5I0

     activity = entrance
license_plate = HOD8639

     activity = exit
license_plate = HOD8639

     activity = entrance
license_plate = 5P2BI95

     activity = entrance
license_plate = 6P58WS2

     activity = exit
license_plate = 5P2BI95

     activity = exit
license_plate = 94KL13X

     activity = exit
license_plate = 6P58WS2

     activity = exit
license_plate = 4328GD8

     activity = exit
license_plate = G412CB7

     activity = exit
license_plate = L93JTIZ

     activity = exit
license_plate = 322W7JE

     activity = exit
license_plate = 0NTHK55

     activity = entrance
license_plate = FLFN3W0

     activity = exit
license_plate = NAW9653

     activity = exit
license_plate = 94MV71O

     activity = exit
license_plate = 13FNH73

     activity = exit
license_plate = V47T75I

     activity = exit
license_plate = R3G7486
*/

-- count logs that better match the theft timeframe in the `bakery_security_logs` table:
SELECT COUNT(*) FROM bakery_security_logs
WHERE (
    month = 7 AND
    day = 28 AND
    year = 2025 AND
    (minute BETWEEN 15 AND 25) AND
    activity = 'exit'
);
/*
Result:
COUNT(*) = 16
*/


-- review license plates that better match the theft timeframe in the `bakery_security_logs` table:
SELECT license_plate FROM bakery_security_logs
WHERE (
    month = 7 AND
    day = 28 AND
    year = 2025 AND
    (minute BETWEEN 15 AND 25) AND
    activity = 'exit'
);
/*
Result:
+---------------+
| license_plate |
+---------------+
| D965M59       |
| HW0488P       |
| HOD8639       |
| 5P2BI95       |
| 94KL13X       |
| 6P58WS2       |
| 4328GD8       |
| G412CB7       |
| L93JTIZ       |
| 322W7JE       |
| 0NTHK55       |
| NAW9653       |
| 94MV71O       |
| 13FNH73       |
| V47T75I       |
| R3G7486       |
+---------------+
*/


-- review the people who took the first flight on July 29, 2025 and had their car spotted (by license plate) leaving the bakery between 10:15 AM to 10:25 AM on July 28, 2025:
SELECT DISTINCT people.id, people.name FROM people
WHERE (
    people.passport_number IN (
        SELECT passport_number FROM passengers
        WHERE passengers.flight_id = 36
    ) AND
    people.license_plate IN (
        SELECT license_plate FROM bakery_security_logs
        WHERE (
            month = 7 AND
            day = 28 AND
            year = 2025 AND
            (minute BETWEEN 15 AND 25) AND
            activity = 'exit'
        )
    )
);
/*
Result:
   id = 398010
 name = Sofia

   id = 467400
 name = Luca

   id = 560886
 name = Kelsey

   id = 686048
 name = Bruce
*/


-- preview first couple of records in the `phone_calls` table:
SELECT * FROM phone_calls LIMIT 5;
/*
Result:
      id = 1
  caller = (123) 555-5144
receiver = (007) 555-2874
    year = 2025
   month = 7
     day = 25
duration = 243

      id = 2
  caller = (741) 555-1748
receiver = (301) 555-4174
    year = 2025
   month = 7
     day = 25
duration = 350

      id = 3
  caller = (022) 555-4052
receiver = (118) 555-8106
    year = 2025
   month = 7
     day = 25
duration = 160

      id = 4
  caller = (704) 555-5790
receiver = (873) 555-3868
    year = 2025
   month = 7
     day = 25
duration = 186

      id = 5
  caller = (645) 555-8082
receiver = (695) 555-0348
    year = 2025
   month = 7
     day = 25
duration = 247
*/


-- count all calls that match the thief's call on the day of the theft on July 28, 2025 that are under 1 minute in duration:
SELECT COUNT(*) FROM phone_calls
WHERE (
    month = 7 AND
    day = 28 AND 
    year = 2025 AND 
    duration <= 60
);
/*
Result:
COUNT(*) = 10
*/


-- preview first few records in `atm_transactions` table:
SELECT * FROM atm_transactions LIMIT 5;
/*
Result:
              id = 1
  account_number = 57022441
            year = 2025
           month = 7
             day = 26
    atm_location = Humphrey Lane
transaction_type = deposit
          amount = 40

              id = 2
  account_number = 39167741
            year = 2025
           month = 7
             day = 26
    atm_location = Daboin Sanchez Drive
transaction_type = withdraw
          amount = 40

              id = 3
  account_number = 93622979
            year = 2025
           month = 7
             day = 26
    atm_location = Carvalho Road
transaction_type = deposit
          amount = 50

              id = 4
  account_number = 11605357
            year = 2025
           month = 7
             day = 26
    atm_location = Humphrey Lane
transaction_type = deposit
          amount = 25

              id = 5
  account_number = 27362189
            year = 2025
           month = 7
             day = 26
    atm_location = Humphrey Lane
transaction_type = deposit
          amount = 75
*/


-- count the withdrawals from an ATM at Leggett Street on July 28, 2025:
SELECT COUNT(*) FROM atm_transactions
WHERE (
    month = 7 AND
    day = 28 AND
    year = 2025 AND 
    atm_location = 'Leggett Street' AND
    transaction_type = 'withdraw'
);
/*
Result:
COUNT(*) = 8
*/


-- count the people who did withdrawals from an ATM at Leggett Street on July 28, 2025:
SELECT DISTINCT COUNT(*) FROM people
WHERE people.id IN (
    SELECT bank_accounts.person_id FROM bank_accounts
    WHERE bank_accounts.account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE (
            month = 7 AND
            day = 28 AND
            year = 2025 AND 
            atm_location = 'Leggett Street' AND
            transaction_type = 'withdraw'
        )
    )
);
/*
Result:
COUNT(*) = 8
*/


-- review the people who did withdrawals from an ATM at Leggett Street on July 28, 2025:
SELECT DISTINCT people.id, people.name FROM people
WHERE people.id IN (
    SELECT bank_accounts.person_id FROM bank_accounts
    WHERE bank_accounts.account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE (
            month = 7 AND
            day = 28 AND
            year = 2025 AND 
            atm_location = 'Leggett Street' AND
            transaction_type = 'withdraw'
        )
    )
);
/*
Result:
   id = 395717
 name = Kenny

   id = 396669
 name = Iman

   id = 438727
 name = Benista

   id = 449774
 name = Taylor

   id = 458378
 name = Brooke

   id = 467400
 name = Luca

   id = 514354
 name = Diana

   id = 686048
 name = Bruce
*/


-- count the people who made sub-1 minute calls on July 28, 2025
SELECT DISTINCT COUNT(*) FROM people
WHERE people.phone_number IN (
    SELECT phone_calls.caller FROM phone_calls
    WHERE (
        month = 7 AND
        day = 28 AND 
        year = 2025 AND 
        duration <= 60
    )
);
/*
Result:
COUNT(*) = 9
*/


-- review the people who made sub-1 minute calls on July 28, 2025
SELECT DISTINCT people.id, people.name FROM people
WHERE people.phone_number IN (
    SELECT phone_calls.caller FROM phone_calls
    WHERE (
        month = 7 AND
        day = 28 AND 
        year = 2025 AND 
        duration <= 60
    )
);
/*
Result:
   id = 395717
 name = Kenny

   id = 398010
 name = Sofia

   id = 438727
 name = Benista

   id = 449774
 name = Taylor

   id = 514354
 name = Diana

   id = 560886
 name = Kelsey

   id = 561160
 name = Kathryn

   id = 686048
 name = Bruce

   id = 907148
 name = Carina
*/


/*
find the thief who:
- took the first flight on July 29, 2025
- had their car spotted (by license plate) leaving the bakery between 10:15 AM to 10:25 AM on July 28, 2025
- made a withdrawal from an ATM on Leggett Street before 10:15 AM on July 28, 2025
- made a sub-1 minute call to someone on July 28, 2025 after 10:15 AM 
*/
SELECT DISTINCT people.id, people.name FROM people
WHERE (
    people.passport_number IN (
        SELECT passport_number FROM passengers
        WHERE passengers.flight_id = (
            SELECT id FROM flights
            WHERE (
                month = 7 AND
                day = 29 AND
                year = 2025
            )
            ORDER BY hour, minute ASC
            LIMIT 1
        )
    ) AND
    people.license_plate IN (
        SELECT license_plate FROM bakery_security_logs
        WHERE (
            month = 7 AND
            day = 28 AND
            year = 2025 AND
            (minute BETWEEN 15 AND 25) AND
            activity = 'exit'
        )
    ) AND
    people.id IN (
        SELECT bank_accounts.person_id FROM bank_accounts
        WHERE bank_accounts.account_number IN (
            SELECT account_number FROM atm_transactions
            WHERE (
                month = 7 AND
                day = 28 AND
                year = 2025 AND 
                atm_location = 'Leggett Street' AND
                transaction_type = 'withdraw'
            )
        )
    ) AND
    people.phone_number IN (
        SELECT phone_calls.caller FROM phone_calls
        WHERE (
            month = 7 AND
            day = 28 AND 
            year = 2025 AND 
            duration <= 60
        )
    )
);
/*
Result:
   id = 686048
 name = Bruce
*/


/*
find the thief's accomplice who:
- answered a sub-1 minute call from the thief on July 28, 2025 after 10:15 AM
*/
SELECT DISTINCT people.id, people.name FROM people
WHERE people.phone_number IN (
    SELECT phone_calls.receiver FROM phone_calls
    WHERE (
        month = 7 AND
        day = 28 AND 
        year = 2025 AND 
        duration <= 60 AND
        caller = (
            SELECT people.phone_number FROM people
            WHERE (
                people.name = 'Bruce' AND
                people.id = 686048
            )
        )
    )
);
/*
Result:
   id = 864400
 name = Robin
*/