Anagrams = ["eat","tea","tan","ate","nat","bat"]

copy = Anagrams.copy()

grouped = []
gr_cnt = 0 # index for `grouped` list
grouped.append([])

track = [] # tracking the added values

for i in range(len(copy)): # sorting strings within list
    text = copy[i]
    sorted_text = "".join(sorted(text))
    copy[i] = sorted_text

# now `copy` is sorted but `Anagrams` is not. But they have the same index for the corresponding elements inside them

for i in range(len(Anagrams)):
    flag = False
    for j in range(len(Anagrams)): 
        if Anagrams[j] not in track: # skips added values after first loop
            if copy[i] == copy[j]:
                grouped[gr_cnt].append(Anagrams[j])
                track.extend(grouped[gr_cnt])
    
    if i!=len(Anagrams)-1 and len(grouped[gr_cnt])>0: # skip when last loop reached
        gr_cnt=gr_cnt+1
        grouped.append([])

print(grouped)


# String sorting 
""" 
text = "eat"
sorted_text = "".join(sorted(text))
print(sorted_text)  #aet
"""

# Using hash-map (Masud suggested) <-- best approach

# Using sum of ASCII values (Shabib suggested) <-- Collision