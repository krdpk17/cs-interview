def expected_value():
    sum = 0
    for dice1 in range(1,7):
        for dice2 in range(1,7):
            if(dice1 > dice2):
                sum += dice1
            else:
                sum += dice2
    print("sum is ", sum)
    expected = sum/36
    return expected

if(__name__ == "__main__"):
    expected = expected_value()
    print(expected)

