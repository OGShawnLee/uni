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


if __name__ == "__main__":
    run_first_task()
