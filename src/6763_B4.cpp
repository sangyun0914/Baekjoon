/**
 *  백준 6763: Speed fines are not fine!

문제
    Many communities now have “radar” signs that tell drivers what their speed is, in the hope that they will slow down.
    You will output a message for a “radar” sign.
    The message will display information to a driver based on his/her speed according to the following table:

    km/h over the limit     Fine
    1 to 20	                $100
    21 to 30	            $270
    31 or above	            $500

입력
    The input will be two integers.
    The first line of input will be speed limit.
    The second line of input will be the recorded speed of the car.

출력
    If the driver is not speeding, the output should be:
    Congratulations, you are within the speed limit!

    If the driver is speeding, the output should be:
    You are speeding and your fine is $F.

    where F is the amount of the fine as described in the table above.

 *  https://www.acmicpc.net/problem/6763
**/

#include <iostream>

int main()
{
    int limit, speed, over;
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    std::cin >> limit >> speed;
    over = speed - limit;
    if (over >= 1 && over <= 20)
        std::cout << "You are speeding and your fine is $100.";
    else if (over >= 21 && over <= 30)
        std::cout << "You are speeding and your fine is $270.";
    else if (over >= 31)
        std::cout << "You are speeding and your fine is $500.";
    else
        std::cout << "Congratulations, you are within the speed limit!";
}