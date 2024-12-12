ans, rules_no, updates_no = 0, 1176, 200
rules, updates = set(), list()

for rule_no in range(0, rules_no):
    rule = tuple(map(int, input().split('|')))
    rules.add(rule)

# read empty line
input()

for update_no in range(0, updates_no):
    update = list(map(int, input().split(',')))
    updates.append(update)

for update in updates:
    good: bool = True
    m: int = int(len(update))
    for i in range(0, m):
        for j in range(i + 1, m):
            if (update[j], update[i]) in rules:
                good = False
    if good:
        ans = ans + update[m // 2]

print(ans)
