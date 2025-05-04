import heapq

list_needto_Modify = [1,2,3,4,5]

heapq.heapify(list_needto_Modify)
heapq.heappush(list_needto_Modify,(priority,item)) #note this is from lowest to hightest number
# so you might need
list_needto_Modify.sort(reverse=True)
heapq.heappop(list_needto_Modify)