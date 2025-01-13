function solution(ineq, eq, n, m) {
    let operator = ineq+eq;
    var answer = 0;
    switch(operator){
        case ">=": 
            if(n >= m){
                answer = 1;
            } else {
                answer = 0;
            }
            break;
                    
        case "<=":
            if(n <= m){
                answer = 1;
            } else {
                answer = 0;
            }
            break;
        
        case "<!":
        if(n < m){
            answer = 1;
        } else {
            answer = 0;
        }
        break;  
                    
        case ">!":
        if(n > m){
            answer = 1;
        } else {
            answer = 0;
        }
        break;  

    }         
                    
    
    return answer;
}