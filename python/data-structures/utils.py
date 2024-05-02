def get_str(prompt: str) -> str:
    return input(prompt + ": ")

def get_int(prompt: str) -> int:
    return int(get_str(prompt))
