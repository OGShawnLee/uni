def get_int(prompt: str) -> int:
    return int(input(f"{prompt}: "))


def get_float(prompt: str) -> float:
    return float(input(f"{prompt}: "))


def get_str(prompt: str) -> str:
    return input(f"{prompt}: ")


def report_value(name: str, value):
    print(f"{name}: {value}")


def is_in_range(value, lower, upper):
    return value >= lower and value <= upper

def is_outside_range(value, lower, upper):
    return value < lower or value > upper