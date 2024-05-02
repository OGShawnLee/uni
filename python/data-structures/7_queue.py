from utils import get_str, get_int

class Element:
    data: int
    next: "Element"

    def __init__(self, data: int):
        self.data = data
        self.next = None

    def print(self, indentation = 0):
        indent = " " * indentation

        if self.next == None:
            print(f"Element {{ data: {self.data} }}")
        else:
            print("Element {")
            print(indent + f"    data: {self.data}")
            print(indent + "    next: ", end = "")
            self.next.print(indentation + 2)
            print(indent + "  }")


class Queue:
    cap: int
    len: int
    front: Element

    def __init__(self, cap: int):
        self.cap = cap
        self.len = 0

    def enqueue(self, data: int):
        if self.len == self.cap:
            raise "Cannot enqueue element: Queue is full"

        child = Element(data)

        if self.len == 0:
            self.front = child
        else:
            child.next = self.front
            self.front = child

        self.len += 1

    def dequeue(self) -> Element:
        if self.len == 0:
            return None

        front = self.front
        self.front = self.front.next
        front.next = None
        self.len -= 1

        return front

    def has_value(self, data: int):
        current = self.front

        while current != None:
            if current.data == data:
                return True

            current = current.next

        return False

    def clear(self):
        self.front = None
        self.len = 0

    def print(self):
        print("Queue {")
        print(f"  cap: {self.cap}")
        print(f"  len: {self.len}")

        if self.front:
            print("  front: ", end = "")
            self.front.print()

        print("}")


cap = get_int("Enter the capacity of the queue")
queue = Queue(cap)

while True:
    print("What do you want to do?")
    print("1. Enqueue")
    print("2. Dequeue")
    print("3. Print")
    print("4. Exit")

    option = get_int(">>> Enter the option")

    if option == 1:
        data = get_int("Enter the data")
        queue.enqueue(data)
        continue

    if option == 2:
        element = queue.dequeue()
        print("Dequeued Element")
        element.print()
        continue

    if option == 3:
        queue.print()
        continue

    if option == 4:
        queue.clear()
        print("Bye")
        break

    print("Invalid Option!")
