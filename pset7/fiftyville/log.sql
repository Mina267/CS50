-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM interviews WHERE month = 7 AND day = 28 ;
SELECT description FROM phone_calls WHERE month = 7 AND day = 28 ;
SELECT * FROM courthouse_security_logs WHERE month = 7 AND day = 28  AND hour = 10 AND minute < 26  AND activity = "exit";
SELECT * FROM atm_transactions WHERE month = 7 AND day = 28  AND  transaction_type = "withdraw" AND atm_location = "Fifer Street";
SELECT * FROM flights WHERE month = 7 AND day = 29  ORDER BY(hour);
SELECT * FROM airports WHERE id = 5 OR id = 8;
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND duration <= 60 ORDER BY(duration);

SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration <=60) 
AND license_plate IN  (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28  AND hour = 10 AND minute < 26  AND activity = "exit");

SELECT * FROM passengers WHERE passport_number IN
   ...> (SELECT passport_number FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration <=60)
   ...> AND license_plate IN  (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28  AND hour = 10 AND minute < 26  AND activity = "exit"));
   
   
SELECT * FROM passengers WHERE passport_number IN
   ...> (SELECT passport_number FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration <=60)
   ...> AND license_plate IN  (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28  AND hour = 10 AND minute < 26  AND activity = "exit"))
   ...> AND flight_id IN (SELECT id FROM flights WHERE month = 7 AND day = 29  ORDER BY(hour));
   
   
SELECT * FROM people WHERE passport_number IN (
   ...> SELECT passport_number FROM passengers WHERE passport_number IN
   ...> (SELECT passport_number FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration <=60)
   ...> AND license_plate IN  (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28  AND hour = 10 AND minute < 26  AND activity = "exit"))
   ...> AND flight_id IN (SELECT id FROM flights WHERE month = 7 AND day = 29  ORDER BY(hour)));
   
   
   SELECT account_number FROM bank_accounts WHERE person_id IN (
   ...> SELECT id FROM people WHERE passport_number IN (
   ...> SELECT passport_number FROM passengers WHERE passport_number IN
   ...> (SELECT passport_number FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration <=60)
   ...> AND license_plate IN  (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28  AND hour = 10 AND minute < 26  AND activity = "exit"))
   ...> AND flight_id IN (SELECT id FROM flights WHERE month = 7 AND day = 29  ORDER BY(hour))));
   
   
SELECT * FROM courthouse_security_logs WHERE month = 7 AND day = 28  AND hour = 10 AND minute < 26  AND activity = "exit" AND license_plate IN (
SELECT license_plate FROM people WHERE id IN(
SELECT person_id FROM bank_accounts WHERE person_id IN (
SELECT id FROM people WHERE passport_number IN (
SELECT passport_number FROM passengers WHERE passport_number IN
(SELECT passport_number FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration <60)
AND license_plate IN  (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28  AND hour = 10 AND minute < 26  AND activity = "exit"))
AND flight_id IN (SELECT id FROM flights WHERE month = 7 AND day = 29  ORDER BY(hour))))));   