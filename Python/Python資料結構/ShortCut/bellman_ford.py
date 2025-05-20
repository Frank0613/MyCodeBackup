def bellman_ford(graph, source):
    distances = {node: float('inf') for node in graph}
    distances[source] = 0
    predecessors = {}

    for i in range(len(graph) - 1):
        for node in graph:
            for neighbor, weight in graph[node].items():
                if distances[node] + weight < distances[neighbor]:
                    distances[neighbor] = distances[node] + weight
                    predecessors[neighbor] = node

    for node in graph:
        for neighbor, weight in graph[node].items():
            if distances[node] + weight < distances.get(neighbor, float('inf')):
                raise Exception("存在父權迴路")

    return distances, predecessors


graph = {
    'A': {'B': 2, 'C': 2},
    'B': {'C': 2, 'D': 4},
    'C': {'A': 1, 'D': 1, 'E': 1},
    'D': {'F': 2},
    'E': {'D': -3},
    'F': {}
}

source_node = 'A'
shortest_paths, predecessors = bellman_ford(graph, source_node)

for target_node, distance in shortest_paths.items():
    path = [target_node]
    current_node = target_node
    while current_node != source_node:
        current_node = predecessors.get(current_node)  
        if current_node is None:
            break
        path.append(current_node)
    path.reverse()
    print(f"Shortest path from {source_node} to {target_node}: distance: {distance} --> {path}")
