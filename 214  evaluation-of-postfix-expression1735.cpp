class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string exp)
    {
                stack <int> s;
        
        for(int i=0 ; i<exp.length() ; i++)
        {
            if(exp[i] >= '0' and exp[i] <= '9')
                s.push(exp[i]-'0');
        
            else
            {
                int operator2 = s.top();
                s.pop();
                
                int operator1 = s.top();
                s.pop();
                
                switch(exp[i])
                {
                    case '+':
                        s.push(operator1 + operator2);
                        break;
                    
                    case '-':
                        s.push(operator1 - operator2);
                        break;
                        
                    case '*':
                        s.push(operator1 * operator2);
                        break;
                        
                    case '/':
                        s.push(operator1 / operator2);
                        break;
                        
                    case '^':
                        s.push(pow(operator1 , operator2));
                        break;
                }
            }
        }
        return s.top();
    }
};
