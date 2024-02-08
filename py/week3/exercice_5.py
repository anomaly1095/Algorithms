from sys import stdin
from collections import namedtuple

Segment = namedtuple('Segment', 'start end')

def optimal_points(segments):
    points = []
    # Sort segments by their end points
    segments.sort(key=lambda x: x.end)

    current_point = segments[0].end
    points.append(current_point)

    for segment in segments:
        # If the current point is not in the current segment, add the end point of the segment
        if current_point < segment.start or current_point > segment.end:
            current_point = segment.end
            points.append(current_point)

    return points

if __name__ == '__main__':
    input_data = stdin.read()
    n, *data = map(int, input_data.split())
    segments = [Segment(data[i], data[i + 1]) for i in range(0, len(data), 2)]
    points = optimal_points(segments)
    print(len(points))
    print(*points)

