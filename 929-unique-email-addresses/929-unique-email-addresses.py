class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        email_set = set()

        for email in emails:
            # split the email from @ and get the first part
            local, domain = email.split('@')
            # join the local and domain
            email_set.add(local.replace('.', '').split('+')[0] + '@' + domain)
            # check if the email is in the set
        return len(email_set)