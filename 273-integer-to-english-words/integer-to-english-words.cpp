class Solution {
public:
    string one(int n){
        if(n==1) return "One";
        if(n==2) return "Two";
        if(n==3) return "Three";
        if(n==4) return "Four";
        if(n==5) return "Five";
        if(n==6) return "Six";
        if(n==7) return "Seven";
        if(n==8) return "Eight";
        if(n==9) return "Nine";

        return "";
    }

    string teen(int n){
        if(n==10) return "Ten";
        if(n==11) return "Eleven";
        if(n==12) return "Twelve";
        if(n==13) return "Thirteen";
        if(n==14) return "Fourteen";
        if(n==15) return "Fifteen";
        if(n==16) return "Sixteen";
        if(n==17) return "Seventeen";
        if(n==18) return "Eighteen";
        if(n==19) return "Nineteen";

        return "";
    }
    string ten(int n){
        if(n==2) return "Twenty";
        if(n==3) return "Thirty";
        if(n==4) return "Forty";
        if(n==5) return "Fifty";
        if(n==6) return "Sixty";
        if(n==7) return "Seventy";
        if(n==8) return "Eighty";
        if(n==9) return "Ninety";

        return "";
    }
    string two(int n){
        if(n==0) return "";
        if(n<10) return one(n);
        if(n<20) return teen(n);
        int t=n/10;
        int rem=n%=10;

        if(t!=0 && rem!=0){
            return ten(t)+ " "+ one(rem);
        }
        else if(t==0 && rem!=0){
            return one(rem);
        }
        else if(rem==0 && t!=0){
            return ten(t);
        }

        return "";
    }

    string three(int num){
        if(num==0) return "";
        int h=num/100;
        int rem=num%=100;

        if(h!=0 && rem!=0){
            return one(h)+" Hundred "+two(rem);
        }
        else if(h==0 && rem!=0){
            return two(rem);
        }
        else if(rem==0 && h!=0){
            return one(h)+" Hundred";
        }

        return "";
    }

    string numberToWords(int num) {
        if(num==0) return "Zero";
        int billion=num/1000000000;
        num%=1000000000;
        int million=num/1000000;
        num%=1000000;
        int thousand=num/1000;
        num%=1000;
        
        string ans="";
        if(billion!=0){
            if(ans.length()!=0) ans+=" ";
            ans+=three(billion)+" Billion";
        }
        if(million!=0){
            if(ans.length()!=0) ans+=" ";
            ans+=three(million)+" Million";
        }
        if(thousand!=0){
            if(ans.length()!=0) ans+=" ";
            ans+=three(thousand)+" Thousand";
        }
        if(num!=0){
            if(ans.length()!=0) ans+=" ";
            ans+=three(num);
        }
        return ans;
    }
};