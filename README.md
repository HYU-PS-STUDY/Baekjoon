# HYU-PS-STUDY


## 스타디 방식

### 1. 각자 자신의 깃허브 아이디 브랜치로 push

```shell
git clone https://github.com/HYU-PS-STUDY/Baekjoon
cd Baekjoon
git checkout -b [깃허브 아이디]

# ...
# 자신이 선정한 2문제  커밋
# ...

git push -u origin [깃허브 아이디]
```

자신이 선정한 2문제는  
`[해당 주차 디렉터리]/[깃허브 아이디]/*` 경로에 넣어서 푸시합니다.

예시)

```shell
.
├── week03-binary-search
│  ├── clean2001
│  ├── leGit-y
│  ├── wimmings
│  └── wonkyDD
│     ├── 문제번호1.cpp
│     └── 문제번호2.cpp
└── week04-greedy
   ├── clean2001
   ├── leGit-y
   ├── wimmings
   └── wonkyDD
```

구조를 위해서 `.gitkeep` 파일을 넣어놨으니  
삭제하고 커밋해주시면 됩니다.


### 2. Push 이후 Pull Request 생성

자신이 정한 2문제를 커밋후  
1개의 pr로 보내주시면 됩니다.


### 3. 코드 리뷰

매주 한명의 pr만 리뷰해주면 됩니다.  
리뷰어는 리뷰를 한뒤 해당 pr을 merge해주시면 됩니다.

이미 리뷰받은 pr은 리뷰할 수 없습니다.
