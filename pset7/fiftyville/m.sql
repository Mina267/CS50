SELECT
    DISTINCT name
FROM
    people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE
    day = "28"
    AND month = "7"
    AND year = "2020"
    AND transaction_type = "withdraw"
    AND atm_location = "Fifer Street"
INTERSECT
SELECT
    name
FROM
    people
    JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE
    day = "28"
    AND month = "7"
    AND year = "2020"
    AND duration < "60"