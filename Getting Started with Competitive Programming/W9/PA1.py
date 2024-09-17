from collections import deque

def bfs(capacity, flow, source, sink, parent):
    visited = [False] * len(capacity)
    queue = deque([source])
    visited[source] = True

    while queue:
        u = queue.popleft()

        for v in range(len(capacity)):
            if not visited[v] and capacity[u][v] - flow[u][v] > 0:
                parent[v] = u
                if v == sink:
                    return True
                queue.append(v)
                visited[v] = True
    return False

def edmonds_karp(capacity, source, sink):
    n = len(capacity)
    flow = [[0] * n for _ in range(n)]
    max_flow = 0
    parent = [-1] * n

    while bfs(capacity, flow, source, sink, parent):
        path_flow = float('Inf')
        s = sink

        while s != source:
            path_flow = min(path_flow, capacity[parent[s]][s] - flow[parent[s]][s])
            s = parent[s]

        max_flow += path_flow
        v = sink
        while v != source:
            u = parent[v]
            flow[u][v] += path_flow
            flow[v][u] -= path_flow
            v = parent[v]

    return max_flow

def can_assign_within_time(N, M, K, spaceships, planets, speeds, time_limit):
    capacity = [[0] * (N + M + 2) for _ in range(N + M + 2)]
    source = N + M
    sink = N + M + 1

    for i in range(N):
        for j in range(M):
            x, y = spaceships[i]
            p, q = planets[j]
            s = speeds[i]
            travel_time = ((p - x) ** 2 + (q - y) ** 2) / (s ** 2)
            if travel_time <= time_limit:
                capacity[i][N + j] = 1

    for i in range(N):
        capacity[source][i] = 1

    for j in range(M):
        capacity[N + j][sink] = 1

    return edmonds_karp(capacity, source, sink) >= K

def minimum_time_to_complete_mission(t, test_cases):
    results = []

    for case in test_cases:
        N, M, K, spaceships, planets, speeds = case
        left, right = 0, 10**18  
        result = -1

        while left <= right:
            mid = (left + right) // 2
            if can_assign_within_time(N, M, K, spaceships, planets, speeds, mid):
                result = mid
                right = mid - 1
            else:
                left = mid + 1

        if result == -1:
            results.append(-1)
        else:
            results.append(result * 60)  

    return results

t = int(input())
test_cases = []

for _ in range(t):
    N, M, K = map(int, input().split())
    spaceships = [tuple(map(int, input().split())) for _ in range(N)]
    planets = [tuple(map(int, input().split())) for _ in range(M)]
    speeds = list(map(int, input().split()))

    test_cases.append((N, M, K, spaceships, planets, speeds))

results = minimum_time_to_complete_mission(t, test_cases)
for res in results:
    print(res)
