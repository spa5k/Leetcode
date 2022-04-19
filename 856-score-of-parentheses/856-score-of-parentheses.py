class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stack=[]

        current=0
        previous=0

        for char in s:
          if char=="(":
            stack.append(current)
            previous,current=0,0
          else:
            top=stack.pop()
            if previous:
                current+=top+previous
            else:
                current+=top+1
          previous=current
        return current