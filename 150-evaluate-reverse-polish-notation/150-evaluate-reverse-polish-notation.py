class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operations = ["+", "-", "*", "/"]

        for i in tokens:
            if i in operations:
                stack = self.handleLastTwo(stack, i)

            else:
                stack.append(int(i))
                
        return stack[0]

    def handleLastTwo(self,stack, operation):
        if len(stack) == 1:
            return stack
        second = stack.pop()
        first = stack.pop()

        if operation == "+":
            res = first + second
            stack.append(res)
        elif operation == "-":
            res = first - second
            stack.append(res)
        elif operation == "*":
            res = first * second
            stack.append(res)
        else:
            res = first / second
            stack.append(int(res))
        return stack