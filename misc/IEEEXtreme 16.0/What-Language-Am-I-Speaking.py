line= input().split(" ")
n= int(line[0])
p= int(line[1])

mp= {}
yes_id= []
no_id= []
Leaf= []
char= []
adj= [[]]
in_degree= []
lang= []

for i in range(n):
    Leaf.append(False)
    char.append('x')
    yes_id.append(0)
    no_id.append(0)
    in_degree.append(0)
    lang.append("")
    adj.append([])
    
for i in range(n):
    line= input().split(" ")
    t= line[0]
    if(t == 'I'):
        iid= int(line[1])
        char[i]= line[2]
        yes_id[i]= int(line[3])
        no_id[i]= int(line[4])
        mp[iid]= i
    else:
        Leaf[i]= True
        iid= int(line[1])
        lang[i]= (line[2])
        mp[iid]= i


for i in range(n):
    if(not Leaf[i]):
        adj[i].append(mp[yes_id[i]])
        adj[i].append(mp[no_id[i]])
        
        in_degree[mp[yes_id[i]]]+= 1
        in_degree[mp[no_id[i]]]+= 1
        
roots= []
for i in range(n):
    if(in_degree[i] == 0 and not Leaf[i]):
        roots.append(i)


present= {""}
Languages= []

def dfs(node):
    if(Leaf[node] == True):
        Languages.append(lang[node])
        return

    dfs(adj[node][0])
    if(not(char[node] in present)):
        dfs(adj[node][1])
    
for _ in range(p):
    s= input()
    present.clear()
    Languages.clear()
    
    for c in s:
        present.add(c)
    
    for r in roots:
        dfs(r)

    Languages.sort()
    out= ""
    for s in Languages:
        out += s +" "

    print(out)
    
