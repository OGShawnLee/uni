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

    result = (a + b ) / (c + d)    
    utils.report_value("Result of (a + b) / (c + d)", result)

    result = (a + (b / c)) / (d + (e / f))
    utils.report_value("Result of (a + (b / c)) / (d + (e / f))", result)

    result = a + (b / (c - d))
    utils.report_value("Result of a (b / (c - d))", result)

if __name__ == "__main__":
    # run_first_task()
    run_second_task()
