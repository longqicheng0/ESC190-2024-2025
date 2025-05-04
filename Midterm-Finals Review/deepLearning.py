import heapq

def calc_activation(image):
    pass #say this is given

def top_N_image(image_list, N, interested_neuron_idx):
    topN = []
    
    for idx, image in image_list:
        activation_energy = calc_activation(image)
        activation_val = activation_energy[interested_neuron_idx]
        
        heapq.heapppush(topN, (activation_val, idx))
        
        if len(topN) > N:
            heapq.heappop(topN)
    
    topN.sort(reverse=True)
    return [(activation_val,image[idx]) for activation_val, idx in topN]
        
            
        
       