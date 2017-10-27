#创建一个用于存储外星人的空列表
aliens = []

#创建30个外星人
for alien_number in range(30):
	new_alien = {'color': 'green', 'points': 5, 'speed': 'slow'}
	aliens.append(new_alien)

#切片显示前五个
for alien in aliens[:5]:
	print(alien)
print("...")

#显示创建了多少个

print("Total number of aliens: "+ str(len(aliens)))

