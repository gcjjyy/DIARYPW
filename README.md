# DIARYPW

도스박물관 카페에서 예전에 받아서 사용중이던 일기장 프로그램이 있었습니다.

주소는 아래와 같지요.

https://cafe.naver.com/olddos/49207

그런데 예전에 2019년에 작성한 저의 일기를 제가 비밀번호를 까먹는 바람에 볼 수가 없었습니다.
그래서 예전 프로그램인데다 아마추어가 작성한 것이니까 풀 수 있지 않을까 하고 분석을 해 본 결과, 다행히 암호를 풀 수 있었습니다.
한글 일기장의 암호화 방식은 두 가지 방식으로 이루어집니다. 일단 문자의 아스키 코드값을 이용하구요.

1. 문자를 저장할 때 (문자코드 * 2) +1 의 형태로 저장.
2. 문자를 저장할때 2글자씩 앞뒤 순서를 바꿔 저장.

예를들면 암호문이 ABCD123 이라면,
순서는 BADC21?3 (3앞에는 널문자가 들어감) 가 되고, 각 문자는 위의 수식으로 바뀌어 저장이 됩니다.

그리고 파일의 첫 10바이트에 저장이 되지요. (최대 9글자)

따라서 암호문을 해독하기 위해선 읽은 문자열의 (문자코드 - 1) / 2를 하면 원래 암호문이 나오게 됩니다.

볼랜드C++ 등으로 컴파일 할 수 있습니다.

```sh
C:\DIARY>BCC -EDIARY.EXE DIARY.CPP
```
