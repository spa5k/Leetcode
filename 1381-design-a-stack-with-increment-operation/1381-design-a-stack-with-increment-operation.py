class CustomStack:
    def __init__(self, maxSize: int):
        self.maxS = maxSize
        self.stack = []
        self.size = 0
        self.container = []

    def push(self, x: int) -> None:
        if self.size < self.maxS:
            self.stack.append(x)
            self.size += 1

    def pop(self) -> int:
        if self.size == 0:
            return -1
        self.size -= 1
        return self.stack.pop()

    def increment(self, k: int, val: int) -> None:
        while self.stack:
            temp = self.pop()
            self.container.append(temp)

        n = k

        while self.container:
            tem = self.container.pop()
            if n > 0:
                self.push(tem + val)
                n -= 1
            else:
                self.push(tem)
        


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)