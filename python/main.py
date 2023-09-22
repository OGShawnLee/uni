import utils


def run_first_task():
    name = utils.get_str("What is your name?").capitalize()
    age = utils.get_int("What is your age?")
    height = utils.get_float("What is your height? (metres)")
    gender = utils.get_str("What is your gender? (M/F)").capitalize()
    crime = utils.get_str("What was your crime?").capitalize()

    utils.report_value("Name", name)
    utils.report_value("Age", age)
    utils.report_value("Height", height)
    utils.report_value("Gender", gender)
    utils.report_value("Crime", crime)


def run_second_task():
    a = utils.get_float("Enter a number for a")
    b = utils.get_float("Enter a number for b")
    c = utils.get_float("Enter a number for c")
    d = utils.get_float("Enter a number for d")
    e = utils.get_float("Enter a number for e")
    f = utils.get_float("Enter a number for f")

    result = (a + b) / (c + d)
    utils.report_value("Result of (a + b) / (c + d)", result)

    result = (a + (b / c)) / (d + (e / f))
    utils.report_value("Result of (a + (b / c)) / (d + (e / f))", result)

    result = a + (b / (c - d))
    utils.report_value("Result of a (b / (c - d))", result)


def run_fourth_task():
    age = utils.get_int("Enter your age in years")
    if utils.is_outside_range(age, 0, 130):
        print("Your age must be between 0 and 130")
    else:
        if utils.is_in_range(age, 18, 25):
            print("You are in the 18-25 age group")
        elif utils.is_in_range(age, 50, 55):
            print("You are in the 50-55 age group")
        else:
            print("You are not in the 18-25 or 50-55 age groups")

    rating = utils.get_int("What was your rating?")

    if rating < 0 or rating > 10:
        print("Your rating must be between 0 and 10")
    else:
        if rating in (9, 10):
            print("Notable")
        elif rating == 8:
            print("Aproved")
        elif rating in (7, 6):
            print("Good")
        else:
            print("You must study more!")

    x = utils.get_int("Enter a number for x")
    y = utils.get_int("Enter a number for y")

    if x == 0 or y == 0:
        print("x and y must be non-zero")
    else:
        print(f"2 + (3 * {x}) = {2 + (3 * x)}")
        print(f"2 + (3 * {y}) = {2 + (3 * y)}")

    a = utils.get_int("Enter a number for a")
    b = utils.get_int("Enter a number for b")
    c = utils.get_int("Enter a number for c")

    if a == b and b == c:
        print("Ordered the same")
    elif a >= b and b >= c:
        print("Descending Order")
    elif a <= b and b <= c:
        print("Ascending Order")
    else:
        print("Unordered")


if __name__ == "__main__":
    # run_first_task()
    # run_second_task()
    run_fourth_task()
