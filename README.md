# 그래프 애플리케이션

이 프로젝트는 그래프의 정점과 간선을 입력받아 DFS(깊이 우선 탐색)를 수행하고, 방문 순서 출력 및 싸이클(데드락)을 감지하는 기능을 제공하는 간단한 C++ 프로그램입니다.

## 주요 기능
- **정점 입력**: 그래프에 정점을 추가합니다.
- **간선 입력**: 각 정점 간의 간선을 설정합니다.
- **DFS 실행**: 사용자가 지정한 시작 정점에서 DFS를 수행합니다.
- **방문 순서 출력**: DFS 수행 중 방문한 정점의 순서를 출력합니다.
- **싸이클 감지**: 그래프에서 싸이클을 감지하고 해당 경로를 출력합니다.

## 사용 방법
1. 콘솔에서 정점의 개수를 입력합니다.
2. 각 정점의 간선을 차례로 설정합니다.
3. DFS를 수행할 시작 정점을 입력합니다.
4. DFS 방문 순서와 싸이클 감지 결과가 출력됩니다.

## 예제 실행 결과
```plaintext
정점(vertex)의 개수를 숫자만 입력 해주세요.
3
0 정점의 간선을 입력해주세요.
1
2
-1
1 정점의 간선을 입력해주세요.
2
-1
2 정점의 간선을 입력해주세요.
0
-1
시작할 정점을 입력해주세요.
0
DFS 방문 순서: 0 -> 1 -> 2
DEADLOCK_DETECTED
0 -> 2
2 -> 0
