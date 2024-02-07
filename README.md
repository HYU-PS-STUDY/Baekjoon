# HYU-PS-STUDY

## Notice

`husky` 를 사용해 현재 커밋 메시지를 강제하고 있습니다.

다음과 같은 의존성 설치가 필요합니다.

### 1. 패키지 매니저 설치

```shell
# https://pnpm.io/installation

# npm이 깔려있다면
npm install -g pnpm

# homebrew를 원한다면
brew install pnpm
```

2. 프로젝트 의존성 설치

```shell
pnpm install
```

이게 전부입니다.  
자동으로 모든 셋업을 완료합니다.

<br>

커밋 메세지는 정규식
> `^\[week-\d+-[a-zA-Z0-9-]+\] (\d+, )*\d+$`

으로 검증하며 자세한 내용은
[husky](/.husky/commit-msg) 에서 확인하실 수 있습니다.

만약 커밋 메세지 강제를 피하고 싶으시다면  
`--no-verify` 옵션을 사용하시면 됩니다.


**예시**

```shell
git commit -m'커밋 메세지' --no-verify
```


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

최소 한명 이상의 pr을 리뷰해주시면 됩니다.  
Merge는 매주 스타디가 끝났을때 해주시면 됩니다.  
