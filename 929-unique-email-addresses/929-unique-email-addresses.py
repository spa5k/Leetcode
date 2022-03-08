class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        email_set=set()

        for email in emails:
            # split the email from @ and get the first part
            local, domain = email.split('@')
            # iterate over the local part and remove all the '.'
            local = local.replace('.', '')
            # iterate over local and ignore everything after +
            local = local.split('+')[0]
            # join the local and domain
            email_set.add(local + '@' + domain)
            # check if the email is in the set
        return len(email_set)