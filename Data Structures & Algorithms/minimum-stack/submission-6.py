class MinStack:

    def __init__(self):
        self.st = []
        self.st_min = []
        

    def push(self, val: int) -> None:
        if (len(self.st_min) != 0):
            if (val <= self.st_min[-1]):
                self.st_min.append(val)
        else:
            self.st_min.append(val)
        self.st.append(val)
        

    def pop(self) -> None:
        if self.st[-1] == self.st_min[-1]:
            self.st_min.pop()
        self.st.pop()

    def top(self) -> int:
        return self.st[-1]

    def getMin(self) -> int:
        return self.st_min[-1]
