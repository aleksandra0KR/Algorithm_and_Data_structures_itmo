n,m = map(int,input().split(' '))
mass = []
for i in range(n):
arr = list(map(int,input().split(' ')))
for k in range(0, m):
mass.append(arr[k])

for i in range(1, len(mass)):
key = mass[i]
j = i-1
while j >=0 and key < mass[j] :
mass[j+1] = mass[j]
j -= 1
mass[j+1] = key

        n1 = int(input())
mass2 = list(map(int,input().split(' ')))
for i in range(1, len(mass2)):
key = mass2[i]
j = i-1
while j >=0 and key < mass2[j] :
mass2[j+1] = mass2[j]
j -= 1
mass2[j+1] = key


        mi = 0
m2i=0
res = 0
while mi<(n*m) and m2i<n1:
if mass2[m2i]<=mass[mi]:
res+=1
mi +=1
m2i+=1

else:
mi+=1

print(res)
