X = 2023
K = 117
R = [93, 123, 141, 168, 178, 205, 233, 243, 247, 262, 264, 279, 312, 361, 365, 384, 401, 410, 464, 467, 503, 522, 564, 570, 580, 605, 616, 632, 636, 669, 693, 700, 718, 720, 725, 732, 760, 774, 807, 826, 829, 832, 867, 868, 877, 920, 925, 945, 953, 964, 1002, 1024, 1027, 1099, 1118, 1148, 1168, 1175, 1207, 1227, 1252, 1254, 1272, 1285, 1297, 1304, 1355, 1381, 1408, 1429, 1436, 1442, 1443, 1459, 1488, 1494, 1501, 1502, 1504, 1512, 1546, 1585, 1609, 1634, 1651, 1659, 1683, 1702, 1704, 1716, 1724, 1767, 1792, 1820, 1845, 1886, 1899, 1935, 1949, 1954, 1962, 1967, 1981, 1995, 2009, 2017, 2143, 2144, 2158, 2160, 2190, 2210, 2224, 2227, 2246, 2269, 2286]
B = [16, 35, 43, 52, 68, 82, 105, 160, 176, 184, 202, 222, 288, 290, 299, 304, 331, 343, 354, 418, 430, 441, 454, 484, 523, 536, 545, 596, 598, 653, 658, 676, 683, 692, 722, 737, 751, 793, 813, 833, 848, 885, 900, 906, 977, 989, 997, 1021, 1045, 1057, 1062, 1070, 1081, 1111, 1123, 1130, 1174, 1184, 1187, 1234, 1264, 1277, 1309, 1327, 1337, 1372, 1389, 1392, 1403, 1411, 1451, 1456, 1458, 1470, 1529, 1552, 1558, 1571, 1576, 1578, 1602, 1616, 1678, 1744, 1747, 1777, 1781, 1785, 1804, 1814, 1832, 1855, 1864, 1866, 1878, 1884, 1905, 1920, 1923, 2012, 2039, 2049, 2068, 2088, 2091, 2100, 2109, 2120, 2126, 2137, 2165, 2184, 2225, 2236, 2253, 2297, 2312]


R.sort()
B.sort()
pos, step=0,0
while pos!=X: #havent reach goal
	if R==[] or B==[]:
		step+=abs(X-pos)
		print step
		break

	elif X>pos:#going right!
		R_now = sorted([i for i in R if i>pos])#acessible locations
		B_now = sorted([i for i in B if i>pos])
		
		if R_now==[] or B_now==[]:
			step+=abs(X-pos)
			print step
			break
		else:
			R_min_index = 0
			r_dist = abs(R_now[R_min_index] - pos)
			B_min_index = 0
			b_dist = abs(B_now[B_min_index]-pos)
			dist_to_goal = abs(X-pos)
			
			closest_stuff = min(r_dist, b_dist, dist_to_goal)
			
			if closest_stuff == dist_to_goal: #goal!
				step+=dist_to_goal
				print step
				break
			elif closest_stuff == r_dist: #found a red portal
				step+=r_dist
				pos=B_now[-1]
				R.pop(R.index(R_now[R_min_index]))
				B.pop(B.index(B_now[-1]))
			else:#found a blue portal
				step+=b_dist
				pos=R_now[-1]
				B.pop(B.index(B_now[B_min_index]))
				R.pop(R.index(R_now[-1]))
			
			
			
	else:#travelling left
		R_now = sorted([i for i in R if i<pos])#acessible locations
		B_now = sorted([i for i in B if i<pos])

		if R_now==[] or B_now==[]:
			step+=abs(X-pos)
			print step
			break
		else:
			R_min_index = -1
			r_dist= abs(R_now[R_min_index]-pos)
			B_min_index = -1
			b_dist = abs(B_now[B_min_index]-pos)
			dist_to_goal = abs(X-pos)
			
			closest_stuff = min(r_dist, b_dist, dist_to_goal)
			
			if closest_stuff == dist_to_goal: #goal!
				step+=dist_to_goal
				print step
				break
			elif closest_stuff == r_dist: #found a red portal
				step+=r_dist
				pos=B_now[0]
				R.pop(R.index(R_now[R_min_index]))
				B.pop(B.index(B_now[0]))
			else:#found a blue portal
				step+=b_dist
				pos=R_now[0]
				B.pop(B.index(B_now[B_min_index]))
				R.pop(R.index(R_now[0]))
