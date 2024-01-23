'''
Calculate trapped water
Approach is to find  water_levl using left side max and right side max
Water_level will be min(max_height(left_side), max_height(right_side))
Once water_level calculated, run through each column to get the trapped water quantity
'''
def trap_water(heights):
    left_max = [0] * len(heights)
    #calculate left side max height for each column except the 1st one
    for x in range(1, len(heights)-1):
        left_max[x] = max(heights[x-1], left_max[x-1])
        
    #calculate right side max height for each column except the last one
    right_max = [0]*len(heights)
    for x in range(len(heights)-2, -1, -1):
        right_max[x] = max(heights[x+1], right_max[x+1])
    
    #calculate the trapped water 
    water_amount = 0
    for x in range(0, len(heights)):
        water_level = min(left_max[x], right_max[x])
        if(water_level >= heights[x]):
            water_amount += water_level - heights[x]
    
    return water_amount        
    



if(__name__ == "__main__"):
    heights = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    res = trap_water(heights)
    print(res)