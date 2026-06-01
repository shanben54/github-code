def findPayment(loan, r, m):
    # 请在此添加代码，补全函数findPayment
    #********** Begin *********#
	return loan*r*(1+r)**m/((1+r)**m-1)
    #********** End *********#

class Mortgage(object):
     def __init__(self, loan, annRate, months):
        # 请在此添加代码，补全函数__init__
        #********** Begin *********#
        self.loan=loan
        self.rate=annRate/100/12
        self.months=months
        self.payment=findPayment(loan,self.rate,months)
        self.paid=[]
        self.owed=[loan]
         #********** End *********#
        self.legend = None

     def makePayment(self):
         # 请在此添加代码，补全函数makePayment
         #********** Begin *********#
         self.paid.append(self.payment)
         last_owed=self.owed[-1]
         interest=last_owed*self.rate
         principal=self.payment-interest
         current_owed=last_owed-principal
         self.owed.appeng(current_owed)
         #********** End *********#

     def getTotalPaid(self):
         # 请在此添加代码，补全函数getTotalPaid
         #********** Begin *********#
         return sum(self.paid)

         #********** End *********#

     def __str__(self):
        return 'The Mortgage is {self.legend}, Loan is {self.loan}, Months is {self.months}, Rate is {self.rate:.2f}, Monthly payment is {self.payment:.2f}'.format(self=self)

if __name__=="__main__": 
    loan, annRate, months = [float(x) for x in input().split()]
    m1 = Mortgage(loan, annRate, months)
    print(m1)
    m1.makePayment()
    m1.makePayment()
    print('Two months payment is {:.2f}'.format(m1.getTotalPaid()))