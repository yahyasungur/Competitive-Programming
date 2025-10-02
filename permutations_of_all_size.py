def CreateQueue():
    """ Creates an empty Queue """
    return []

def Enqueue(item, Queue):
    """ Add item to the end (back) of the Queue """
    Queue.append(item)

def Dequeue(Queue):
    """ Remove and return the item at the front of the Queue """
    return Queue.pop(0)

def Front(Queue):
    """ Return the value of the current front item without removing it """
    return Queue[0]

def IsEmptyQueue(Queue):
    """ Check whether the Queue is empty """
    return Queue == []

def permutations_of_all_size(lst):
	output = []
	queue = CreateQueue()
	for i in range(len(lst)):
		output.append([lst[i]])
		Enqueue(([lst[i]], lst[:i]+lst[i+1:]), queue)
	if len(lst) == 1:
		return output
	while not IsEmptyQueue(queue):
		initializer, remainings = Dequeue(queue)
		if len(remainings) == 1:
			output.append(initializer + remainings)
			continue
		for j in range(len(remainings)):
			new_permutation = initializer + [remainings[j]]
			output.append(new_permutation)
			Enqueue((new_permutation, remainings[:j]+remainings[j+1:]), queue)
	return output

print(permutations_of_all_size([1,2,3]))