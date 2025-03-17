# 📌 GitHub 협업 가이드 (Fork 기반 & Shared Repo 기반)

이 문서는 GitHub에서 협업하는 다양한 방법을 정리합니다.  
✅ **Fork 기반 협업**  
✅ **Shared Repository(공유 저장소) 기반 협업**  
✅ **Git Flow 전략 적용**  

---

## 🔹 **1. GitHub 협업 방식 개요**
GitHub 협업 방식은 크게 **두 가지**로 나뉩니다.

| 협업 방식 | 설명 | 사용 예시 |
|-----------|------|---------|
| **Fork 기반 협업** | 원본 저장소(A)를 포크한 후 작업, PR(Pull Request)로 반영 | 오픈소스 프로젝트, 외부 기여 |
| **Shared Repository 협업** | 같은 저장소에서 브랜치를 나눠 작업, PR 또는 직접 Merge | 팀 내 개발, 기업 프로젝트 |

---

## 🔹 **2. Fork 기반 협업 (유저 A: 저장소 오너, 유저 B: 포크한 유저)**
포크 기반 협업에서는 **각자가 독립적인 저장소를 유지하면서 원본 저장소(A)로 기여**합니다.

### 🏁 **[유저 A] 원본 저장소 생성**
```sh
git init
git add .
git commit -m "Initial commit"
git branch -M main
git remote add origin https://github.com/A/repo.git
git push -u origin main
```

GitHub에서 저장소를 생성 후 유저 B가 포크할 수 있도록 공개(Public) 설정

### 🔄 [유저 B] A의 저장소 포크 후 로컬 클론
``` sh
# 1. 원본 저장소(A)를 포크
# 2. 포크한 저장소를 로컬로 클론
git clone https://github.com/B/repo.git
cd repo

# 3. A의 원본 저장소(upstream) 추가
git remote add upstream https://github.com/A/repo.git

# 4. 원격 저장소 확인 (origin: 포크한 저장소, upstream: 원본 저장소)
git remote -v
```

### 🚀 [유저 B] 기능 개발 및 PR 생성

```sh
# 1. 새로운 기능을 위한 브랜치 생성
git checkout -b feature-branch

# 2. 코드 수정 후 커밋
git add .
git commit -m "새 기능 추가"

# 3. 포크한 저장소(origin)로 푸시
git push origin feature-branch

```

### 👀 [유저 A] PR 리뷰 및 병합
* 1.GitHub에서 PR 확인 및 코드 리뷰
* 2.PR 병합 (Merge)
```sh
git checkout main
git merge feature-branch
git push origin main
```
* 브랜치 삭제 (필요 시)
``` sh
git branch -d feature-branch
git push origin --delete feature-branch
```

### 🔄 [유저 B] 원본 저장소와 동기화
``` sh
# 1. 원본 저장소(A)의 최신 코드 가져오기
git checkout main
git fetch upstream
git merge upstream/main

# 2. 포크 저장소(origin)에도 최신 코드 반영
git push origin main
```

### 🔹 3. Shared Repository (공유 저장소) 협업
* 같은 저장소를 사용하는 팀원 간 협업 방법

🏁 브랜치 전략

|Branch|explation|
|----|----|
|main 	    |안정적인 배포 버전 유지|
|develop 	|새로운 기능 개발을 위한 기본 브랜치|
|feature 	|새로운 기능 개발용 브랜치 (작업 후 develop으로 병합)|
|hotfix 	|긴급 버그 수정 (작업 후 main과 develop에 병합)|


### 🔄 협업 흐름 (기본적인 Feature Branch Workflow)
```sh
# 1. 최신 코드 가져오기
git checkout develop
git pull origin develop

# 2. 기능 개발 브랜치 생성
git checkout -b feature/new-feature

# 3. 코드 수정 후 커밋
git add .
git commit -m "새 기능 추가"

# 4. 원격 저장소로 푸시
git push origin feature/new-feature

# 5. GitHub에서 PR 생성 후 리뷰 요청
# 6. PR이 승인되면 develop 브랜치로 병합
```

### 🔹 4. Git Flow 전략 적용
Git Flow는 브랜치를 체계적으로 관리하는 방식으로, 팀 협업에서 많이 사용됩니다.

#### 📌 Git Flow 주요 브랜치

|브랜치|설명|
|---|---|
|main	    |배포용 브랜치|
|develop	|개발 브랜치|
|feature/*	|기능 개발 브랜치|
|release/*	|배포 준비 브랜치|
|hotfix/*	|긴급 버그 수정 브랜치|

#### 🚀 Git Flow 협업 방식

``` sh
# 1. Git Flow 초기화 (처음 한 번만 실행)
git flow init

# 2. 새로운 기능 개발 시작
git flow feature start new-feature

# 3. 코드 수정 후 커밋
git add .
git commit -m "새 기능 개발"

# 4. 기능 개발 완료 후 develop 브랜치로 병합
git flow feature finish new-feature
```
### 🔹 5. 전체 협업 흐름 정리
#### ✅ Fork 기반 협업
``` txt
┌──────────────────────────┐
│   [user A] repos         │
│   https://github.com/A   │
└──────────────────────────┘
          (Fork)
┌──────────────────────────┐
│   [user B] folk repos    │
│   https://github.com/B   │
└──────────────────────────┘
          (Clone)
     ┌────────────────┐
     │  [local env]   │
     └────────────────┘
        (작업 후 Push)
[포크 저장소(B)] → PR 요청 → [원본 저장소(A)]

```

#### ✅ Shared Repository 협업
``` plaintext
┌────────────────────────────┐
│   [원격 저장소] GitHub    │
│     origin/main           │
└────────────────────────────┘
             ⬆️ (Push)
 ┌────────────────────┐
 │   [개발자 A]       │
 │   develop 브랜치    │
 └────────────────────┘
        ⬇️ (Pull)
 ┌────────────────────┐
 │   [개발자 B]       │
 │   develop 브랜치    │
 └────────────────────┘
 ```

#### 🎯 6. 협업 시 주의할 점
✔️ PR을 작은 단위로 생성하여 리뷰를 쉽게 하자
✔️ Merge 전 항상 최신 코드(git pull)를 가져오자
✔️ 충돌 방지를 위해 브랜치 전략을 지키자
✔️ 팀 내 Git 컨벤션을 정하고 따르자
