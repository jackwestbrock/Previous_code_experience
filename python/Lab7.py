from random import shuffle, choice
door_nums = [0,1,2]
good_award = 'car'
bad_award = 'goat'
awards = [good_award, bad_award, bad_award]



def monty_hall_game(u_choice, switch):
    shuffle(awards)
    doors = dict(zip(door_nums, awards))
    remaining_doors = [x for x in door_nums if x != u_choice]
    for door_num in remaining_doors:
        if doors[door_num] == bad_award:
            remaining_doors.remove(door_num)
    
    switched_door = remaining_doors[0]
    final_door = switched_door if switch else u_choice
    win_car = doors[final_door] == good_award
    return win_car



def multiple_monty_hall(games, switch):
    wins = 0
    for i in range(games):
        u_choice = choice(door_nums)
        win_car = monty_hall_game(u_choice, switch)
        wins += int(win_car)
    win_prob = wins/games
    print('Trial times: {} '.format(games))
    print('Switching: {} '.format(switch))
    print('Probability: {}'.format(win_prob))
        

games = int(input('How many games would you play? '))
switch = int(input('Will you switch? (1-yes/0-No '))

multiple_monty_hall(games, switch)

