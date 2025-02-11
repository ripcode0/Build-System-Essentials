### **Git 브랜치 명령어**

| **명령어** | **설명** |
|------------|---------|
| `git branch` | 로컬 브랜치 목록 확인 |
| `git branch -r` | 원격 브랜치 목록 확인 |
| `git branch -a` | 로컬 및 원격 브랜치 목록 확인 |
| `git branch <branchname>` | 새로운 브랜치 생성 (HEAD 변경 없음) |
| `git branch -m <oldbranchname> <newbranchname>` | 브랜치 이름 변경 |
| `git branch -d <branchname>` | 로컬 브랜치 삭제 (병합된 브랜치만 가능) |
| `git branch -D <branchname>` | 강제 로컬 브랜치 삭제 (병합되지 않아도 삭제) |
| `git push origin --delete <branchname>` | 원격 브랜치 삭제 |
| `git checkout <branchname>` | 특정 브랜치로 이동 |
| `git checkout -b <branchname>` | 새 브랜치를 만들고 이동 |
| `git switch <branchname>` | 특정 브랜치로 이동 (`checkout` 대체) |
| `git switch -c <branchname>` | 새 브랜치를 만들고 이동 (`checkout -b` 대체) |
| `git merge <branchname>` | 현재 브랜치에 `<branchname>`을 병합 |
| `git rebase <branchname>` | 현재 브랜치를 `<branchname>`의 최신 커밋 위로 재배치 |
| `git fetch` | 원격 저장소의 최신 변경 사항 가져오기 (병합 없음) |
| `git fetch origin <branchname>` | 특정 원격 브랜치 가져오기 |
| `git pull` | 원격 저장소에서 변경 사항 가져와 현재 브랜치와 병합 |
| `git push origin <branchname>` | 로컬 브랜치를 원격 저장소에 푸시 |
| `git push --set-upstream origin <branchname>` | 원격 저장소에 새로운 브랜치 생성 및 업스트림 설정 |
| `git log --oneline --decorate --graph --all` | 브랜치 구조 시각화 |
