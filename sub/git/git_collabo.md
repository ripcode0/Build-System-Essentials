## 협업 방식 개요
유저 B는 A의 저장소를 포크(Fork) 한 후 자신의 원격 저장소에서 작업합니다. 이후 변경 사항을 A의 원격 저장소(오리지널 저장소)로 반영하려면 Pull Request(PR) 를 보내야 합니다.
A는 PR을 검토한 후 병합할 수 있습니다.

---
### ① 유저 A (저장소 오너)
#### 1. GitHub에서 저장소 생성

``` sh
git init
git add .
git commit -m "Initial commit"
git branch -M main
git remote add origin https://github.com/A/repo.git
git push -u origin main
```

#### 2.유저 B가 협업할 수 있도록 저장소를 공개(public)하거나 초대

---

### ② 유저 B (포크 및 로컬 클론)
#### 1. A의 저장소를 포크(Fork)

* GitHub에서 A/repo를 포크하여 B/repo 생성됨.
#### 2. 포크한 저장소를 로컬에 클론

``` sh
git clone https://github.com/B/repo.git
cd repo
```
#### 3. A의 원본 저장소를 원격 추가 (업스트림 설정)

``` sh
git remote add upstream https://github.com/A/repo.git
git remote -v  # 원격 저장소 확인 (origin: 본인 repo, upstream: A의 repo)
```
---
### ③ 유저 B (새 브랜치에서 작업)
#### 1. 새 브랜치 생성 및 작업

``` sh
git checkout -b feature-branch
# 파일 수정
git add .
git commit -m "새 기능 추가"
```
#### 2. 포크한 저장소(origin)로 푸시

``` sh
git push origin feature-branch
```
#### 3. GitHub에서 PR 생성

* GitHub에서 B/repo로 이동 → "New pull request" 버튼 클릭
* B/repo(feature-branch) → A/repo(main) 방향으로 PR 생성
* A가 검토 후 머지할 수 있도록 PR 설명 작성
----
### ④ 유저 A (PR 리뷰 및 병합)
#### 1. GitHub에서 PR 확인 및 코드 리뷰

* 변경 사항 확인 후 코멘트 달기 또는 승인
* 필요 시 B에게 수정 요청 (B가 로컬에서 수정 후 git push 하면 PR에 반영됨)

#### 2. PR을 머지

* 문제가 없다면 "Merge pull request" 클릭하여 main 브랜치에 병합
* 병합 후 브랜치 삭제 가능 (Delete branch)

---

### ⑤ 유저 B (업스트림 변경 사항 반영)
B는 A의 저장소가 최신 상태로 유지되므로, 본인 로컬 저장소도 이를 반영해야 함.

#### 1. 최신 코드 가져오기

``` sh
git checkout main
git fetch upstream
git merge upstream/main
```

#### 2. 포크 저장소(origin)에도 최신 코드 반영

```sh
git push origin main
새로운 작업을 위해 다시 브랜치 생성
```

``` sh
git checkout -b another-feature
```

#### 3. 협업 시 주의할 점
* PR을 자주 생성하고 작은 단위로 작업하기 (큰 기능을 한꺼번에 PR로 보내면 코드 리뷰가 어려움)
* A의 저장소에서 변경 사항이 생겼다면 B는 항상 fetch upstream 후 작업할 것
* 같은 브랜치에서 여러 사람이 동시에 작업하지 않기 (충돌 위험)
* PR 승인 전까지 작업 브랜치는 수정 가능 (강제 푸시 시 주의!)

