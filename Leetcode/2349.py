from sortedcontainers import SortedList

class NumberContainers:
    def __init__(self):
        self.Container: dict[int, int] = {}
        self.NumberList: dict[int, SortedList[int]] = {}

    def change(self, index: int, number: int) -> None:
        if self.Container.get(index, 0) != 0:
            x = self.Container[index]
            self.NumberList[x].discard(index)

        self.Container[index] = number

        if self.NumberList.get(number, None) is None:
            self.NumberList[number] = SortedList()

        self.NumberList[number].add(index)

    def find(self, number: int) -> int:
        if self.NumberList.get(number, None) is None:
            return -1

        if len(self.NumberList[number]) == 0:
            return -1

        return self.NumberList[number][0]
        

if __name__ == "__main__":
    obj = NumberContainers()
    obj.change(1, 1)
    print(obj.find(1))
