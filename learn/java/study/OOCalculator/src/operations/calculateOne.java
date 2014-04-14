package operations;

import java.math.BigDecimal;


public class calculateOne{
	operationBase cal=null;
	public calculateOne(BigDecimal num1,BigDecimal num2,char op)
	{
		switch(op)
		{
		case '+':cal=new operationAdd(num1,num2);break;
		case '-':cal=new operationSub(num1,num2);break;
		case '*':cal=new operationMul(num1,num2);break;
		case '/':cal=new operationDiv(num1,num2);break;
		case '^':cal=new operationPow(num1,num2);break;
		}
	}
	public BigDecimal getResult()
	{
		return cal.getResult();
	}
}

abstract class operationBase {
	BigDecimal num1;
	BigDecimal num2;
	operationBase(BigDecimal num1,BigDecimal num2){
		this.num1=num1;
		this.num2=num2;
	}
	abstract BigDecimal getResult();
}

class operationAdd extends operationBase
{
	operationAdd(BigDecimal num1, BigDecimal num2) {
		super(num1, num2);
	}
	BigDecimal getResult()
	{
		return num1.add(num2);
	}
}

class operationSub extends operationBase
{
	operationSub(BigDecimal num1, BigDecimal num2) {
		super(num1, num2);
	}

	BigDecimal getResult()
	{
		return num1.subtract(num2);
	}
}

class operationMul extends operationBase
{
	operationMul(BigDecimal num1, BigDecimal num2) {
		super(num1, num2);
	}

	BigDecimal getResult()
	{
		return num1.multiply(num2);
	}
}

class operationDiv extends operationBase
{
	operationDiv(BigDecimal num1, BigDecimal num2) {
		super(num1, num2);
	}

	BigDecimal getResult()
	{
		return num1.subtract(num2);
	}
}

class operationPow extends operationBase
{
	operationPow(BigDecimal num1, BigDecimal num2) {
		super(num1, num2);
	}

	BigDecimal getResult()
	{
		return num1.pow(num2.intValue());
	}
}
