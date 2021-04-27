- 지윤님이 정리한 수업 내용

```
[TOC]

<br>

# REST API

<br>

**API(Application Programming Interface)**

- 프로그래밍 언어가 제공하는 기능을 수행할 수 있게 만든 인터페이스
  - 어플리케이션과 프로그래밍으로 소통하는 방법
- 프로그래밍을 활용해서 할 수 있는 어떤 것
- CLI, GUI는 각각 명령줄과 그래픽(아이콘)을 통해서 특정 기능을 수행하는 것이며 API는 프로그래밍을 통해 그 일을 수행할 수 있음
- 다양한 interface 중 하나
  - CLI(ex. git bash), GUI(바탕화면 바로가기), API(ex.코드)

<br>

**Web API**

- 웹 어플리케이션 개발에서 다른 서비스에 요청을 보내고 응답을 받기 위해 정의된 명세
- 현재 웹 개발은 추가로 직접 모든 것을 개발하지 않고 여러 Open API를 가져와서 활용하는 추세
  - ex) 구글, 카카오 지도 API, 우편번호, 도로명, 지번 소 검색 API 등
    - 보통 읽어들이기 때문에 GET이 많음

<br>

**API Server**

> "프로그래밍을 통한 요청에 JSON을 응답하는 서버를 만들자"

![image-20210427092131286](13_django_REST_API_framework.assets/image-20210427092131286.png)

![image-20210427092349462](13_django_REST_API_framework.assets/image-20210427092349462.png)

![image-20210427092401445](13_django_REST_API_framework.assets/image-20210427092401445.png)

**Response JSON 응답 객체**

- ex) Youtube Data API, Naver Papago 번역 API, Kakao Map API, TMDB API

<br>

## RESTful API

**REST**

> **REpresentational State Transfer**
>
> 어떤 의미를 가지고 있는지 명확하면 REST로 볼 수 있다.
>
> "자원과 주소를 지정하는 방법"

- 웹 설계 상의 장점을 최대한 활용할 수 있는 아키텍처 **방법론**
- 네트워크 아키텍쳐 원리의 모음
  - 자원을 정의
  - 자원에 대한 주소를 지정하는 방법
- REST원리를 따르는 시스템 혹은 API를 **RESTful API**라고 하기도 함

<br>

> SOAP vs REST? (정처기)
>
> |      | SOAP     | REST            |
> | ---- | -------- | --------------- |
> |      | 프로토콜 | 아키텍쳐 스타일 |

<br>

## REST 구성

- URI (자원)
- HTTP Method (행위)
- Representation (표현)

<br>

PUT : 자원의 전체 교체, 자원 교체시 모든 필드 필요

(만약 전체가 아닌 일부만 전달할 경우, 전달한 필드외 모두 null or 초기값 처리되니 주의!)

PATCH : 자원의 부분 교체, 자원 교체시 일부 필드 필요

<br>

# Django REST Framework

https://www.django-rest-framework.org/

<br>

​```bash
$ django-admin startproject drf .
$ python -m venv venv
$ source venv/Scripts/activate
$ pip install django
$ python manage.py startapp articles # settings.py 앱 등록
​```

<br>

## CRUD

​```python
# urls.py
from django.urls import path, include

# urlpatterns에 추가
path('api/v1/', include('article.urls')),
​```

​```python
# article/urls.py
from django.urls import path
from . import views

urlpatterns = [
    path('articles/', views.article_list), # 이제 앱 네임 필요없음
]
​```

​```python
# articles/views.py

from django.shortcuts import render

# Create your views here.

def article_list(request):
    pass
​```



​```python
# articles/models.py
from django.db import models

# Create your models here.
class Article(models.Model):
    title = models.CharField(max_length=50)
    content = models.TextField()
    created_at = models.DateTimeField(auto_now_add=True)
​```

​```bash
$ python manage.py makemigrations
$ python manage.py migrate
​```

​```bash
$ pip install django-seed
$ pip install djangorestframework
# settings.py 등록 ('django-seed', 'rest_framework',)
​```

(전역에 한번도 설치를 안했어서 자동완성 쓰기위해)

​```bash
$ deactivate
$ pip install djangorestframework
$ source venv/Scripts/activate
​```

​```bash
$ python manage.py seed articles --number=10
​```



### serializer

- models.py를 생성하고 modelform을 사용하여 html을 전송했는데, 이제 modles.py를 기반으로 serializer을 이용함.
- 인자가 *kwargs
  - data=request.data는 request.POST
  - serializer.data는 이를 포장

​```python
# articles/serializers.py
from rest_framework import serializers
from .models import Article

class ArticleListSerializer(serializers.ModelSerializer):
    class Meta():
        model = Article
        fields = '__all__'
​```

- 이름에 굳이 List를 포함하는 이유 : 



CBV (Class Based View) : 기본 기능을 빠르게 만들기가 쉬움

FBV (Function Based View: 커스텀하기가 좋음



🔴GET /movies

🟡GET /movies/:id

🟢POST /movies

🟡PUT / movies/:id

🟡DELETE /movies/:id

> �� : 전체를 가져와 보여주는 것이 목적
>
> �� : 보여줄지, 수정할지 ,지울지 기존의 정보가 있는 상태
>
> �� : 생성,. 기존의 정보가 없는 상태



​```python
# articles/views.py

from django.shortcuts import render, get_list_or_404 # 추가
from.serializers import ArticleListSerializer

from rest_framework.response import Response
# render는 HTML을 보여주는데 목적, Response는 Json을 보여주는데 목적이 있음
from rest_framework.decorators import api_view
# 템플릿으로 예쁘게 json을 보여줌. 이게 사용자에게 보여지진 않음.

@api_view(['GET']) # GET이 디폴트지만 명시해주는게 좋음
def article_list(request):
    articles = get_list_or_404(Article)
    serializer = ArticleListSerializer(articles, many=True) # form의 역할을 대체, 복수임을 알림
    return Response(serializer.data)
​```



### Postman

- 요청 주고받기를 미리 해볼 수 있음

- 확장 프로그램 설치

https://chrome.google.com/webstore/detail/postman/fhbjgbiflinjbdggehcddcbncdddomop?hl=ko

- chrome://apps/
- 사용해보기
  - http://127.0.0.1:8000/ 입력 (https는 안되는듯)
  - Pretty : 하이라이트 처리
    Raw : 로우
    Preview : 사용자 화면 미리보기
  - http://127.0.0.1:8000/api/v1/articles/ 입력
    - json형식만 보내주는 걸 볼 수 있음
- save 또는 ctrl + s로 프로젝트를 폴더별로 저장해서 여러가지를 편하게 테스트해볼 수 있음



​```python
# articles/serializers.py

# 클래스 추가
class ArticleSerializer(serializers.ModelSerializer):
    class Meta():
        model = Article
        fields = '__all__'
​```

​```python
# articles/urls.py

path('articles/<int:article_pk>/', views.article_detail), # 추가
​```

​```python
# import문
get_object_or_404 # django.shortcuts 추가
from .models import Article, Comment
ArticleSerializer # .models 추가

# detail, 특정 게시물만 요청
@api_view(['GET'])
def article_detail(request, article_pk)
    article = get_object_or_404(Article, pk=article_pk)
    serializer = ArticleSerializer(article)
    # 복수형으로 하지 않는 건 하나의 구조 안에 여러 요소를 가지고 있기 때문. form과 같음
    return Response(serializer.data)
​```

- serializer은 데이터가 아니라 복수(가능) 데이터의 집합체 



**생성 구현 (POST)**

- id값을 미리 알 수 없으므로 pk가 없는 주소를 사용(article_list함수)
- POST방식이므로 기존의 GET으로 전체 데이터 조회를 if문 분기처리

​```python
# views.py

@api_view(['GET', 'POST']) # POST 추가
def article_list(request):
    if request.method == 'GET':
        articles = get_list_or_404(Article)
        serializer = ArticleListSerializer(articles, many=True) # form의 역할을 대체, 복수임을 알림
        return Response(serializer.data)
    elif request.method == 'POST': # 보통 유효성검사를 고려했었던 것과 달리 HTML을 보내는게 아니기 때문에 유효하지 않은 데이터라는 것만 알려주면 될 것.
        serializer = ArticleListSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.error, status=400) # 유효하지않은 것도 보여주기 위해, status 변경
​```

- create를 위해서는 사용자에게 데이터를 우선 보내줘야 함.

  - POST로 바꾸면 Body란이 활성화 됨.
    - form-data형태의 key-value를 입력

  - Postman에서 form column하나 체크박스 해제하면 에러 문구 볼 수 있음
    - {"content":["This field is required."]}
    - 문제 : 오류가 나도 Status 200 OK로 떠 있음.
      - 해결 : status=400 옵션

​```python
# def article_list(request):에서 에러를 보여주는
# 첫번째 방법
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=400)
   
# 두번째 방법
        if serializer.is_valid(raise_exception=True): # 이 옵션이 밑의 줄과 똑같이 에러를 보여줌
            serializer.save()
            return Response(serializer.data)
        # return Response(serializer.errors, status=400) # 유효하지않은 것도 보여주기 위해
​```



**삭제 구현 (DELETE)** 

​```python
# views.py

@api_view(['GET', 'DELETE'])
def article_detail(request, article_pk):
    article = get_object_or_404(Article, pk=article_pk) # 언제든 쓰므로 앞으로 뺀다.

    if request.method == 'GET':
        serializer = ArticleSerializer(article)
        return Response(serializer.data)
    elif request.method == 'DELETE': # 찾아 삭제해야함
        article.delete()
        data = {
            'message': '성공적으로 삭제되었습니다.', # 보통은 True값을 줘서 FE에서 처리
            # 'success': True,
            # 'message': f'{article_pk}번글 삭제'
        }
        return Response(data, status=200) # status=204를 하면 삭제는 되면서 아예 메시지가 뜨지 않음
​```



**수정 구현 (PUT)** 

​```python
# views.py

@api_view(['GET', 'DELETE', 'PUT'])
def article_detail(request, article_pk):
    article = get_object_or_404(Article, pk=article_pk) # 언제든 쓰므로 앞으로 뺀다.

    if request.method == 'GET':
        serializer = ArticleSerializer(article)
        return Response(serializer.data)
    elif request.method == 'DELETE': # 찾아 삭제해야함
        article.delete()
        data = {
            'message': '성공적으로 삭제되었습니다.', # 보통은 True값을 줘서 FE에서 처리
            # 'success': True,
            # 'message': f'{article_pk}번글 삭제'
            # 'article_pk': article_pk
        }
        return Response(data, status=200) # status=204를 하면 삭제는 되면서 아예 메시지가 뜨지 않음
    elif request.method == 'PUT':
        serializer = ArticleSerializer(article, data=request.data)
        if serializer.is_valid(raise_exception=True):
            serializer.save()
            return Response(serializer.data)
​```



## 1: N

**댓글 기능 구현**

- 모델링

​```python
# models.py

class Comment(models.Model):
    article = models.ForeignKey(Article, on_delete=models.CASCADE) # on_delete 옵션 필수
    content = models.TextField()
    created_at = models.DateTimeField(auto_now_add=True)
​```

​```bash
$ python manage.py makemigrations
$ python manage.py migrate
$ python manage.py seed articles --number=10
​```



​```python
# serializers.py

from .models import Article, Comment

class CommentSerializer(serializers.ModelSerializer):
    class Meta():
        model = Comment
        fields = '__all__'
​```



​```python
# urls.py

path('comments/', views.comment_list), # 일단 comments만 조작해보자
​```



​```python
# views.py

from .models import Article, Comment
from.serializers import ArticleListSerializer, ArticleSerializer, CommentSerializer

@api_view()
def comment_list(request):
    comments = get_list_or_404(Comment)
    serializer = CommentSerializer(comments, many=True)
    return Response(serializer.data)
​```



- 댓글 하나 조회

​```python
# urls.py
path('comments/<int:comment_pk>/', views.comment_detail),
​```

​```python
# views.py
@api_view()
def comment_detail(request, comment_pk):
    comment = get_object_or_404(Comment, pk=comment_pk)
    serializer = CommentSerializer(comment)
    return Response(serializer.data)
​```



**댓글 생성**

- 게시물과 댓글 합치기

​```python
# urls.py
path('articles/<int:article_pk>/comments/', views.comment_create),
​```

​```python
# views.py

@api_view(['POST'])
def comment_create(request, article_pk):
    article = get_object_or_404(Article, pk=article_pk)
    serializer = CommentSerializer(data=request.data)
    if serializer.is_valid(raise_exception=True):
        serializer.save(article=article) # 여기서 저장
        return Response(serializer.data)
​```



- 문제점

{"article":["This field is required."]}

​```python
# serializers.py 수정
class CommentSerializer(serializers.ModelSerializer):
    class Meta():
        model = Comment
        fields = '__all__'
        read_only_fields = ('article',) # 추가
        # commit=False와 같이 article을 저장하지 않겠다는 것. views의 함수에서 저장된다.
​```



**댓글 수정, 삭제 기능**

- comment_detail에 추가

​```python
# views.py

@api_view(['GET', 'PUT', 'DELETE'])
def comment_detail(request, comment_pk):
    comment = get_object_or_404(Comment, pk=comment_pk)

    if request.method == 'GET':
        serializer = CommentSerializer(comment)
        return Response(serializer.data)
    elif request.method == 'PUT':
        pass
    elif request.method == 'DELETE':
        comment.delete()
        data = {
            'message': True,
        }
        return Response(data, status=204)
​```



### NESTED

- 조회할 때 댓글이랑 게시물이 연결되어있지 않은 문제

  - index에서 댓글도 따로 요청해야하고 게시물 요소도 따로 요청해야 함

  => NESTED 구조를 만들어야

- 방법 1

​```python
# serializers.py

class ArticleSerializer(serializers.ModelSerializer):
    # article과 연결되어있는 comment들을 다 가져온다.
    # 사용자에게 정보를 받는게 목적이 아니므로 is_valid통과 위해 read_only옵션 설정
    comment_set = serializers.PrimaryKeyRelatedField(many=True, read_only=True)  
    class Meta():
        model = Article
        fields = '__all__'
​```

- 결과

​```json
{
    "id": 16,
    "comment_set": [
        6
    ],
    "title": "Production focus money.",
    "content": "Television laugh vote something south long red. Just religious wall join open assume thus.",
    "created_at": "1973-01-28T16:26:04Z"
}
​```

#### N의 개수 세기

- 방법 2 

​```python
class CommentSerializer(serializers.ModelSerializer):
    class Meta():
        model = Comment
        fields = '__all__'
        read_only_fields = ('article',)

class ArticleSerializer(serializers.ModelSerializer):
    comment_set = CommentSerializer(many=True, read_only=True) # serializer 자체를 가져올 수 있음. 위치는 가져오는 게  위에 있어야
    comment_count = serializers.IntegerField(source='comment_set.count', read_only=True) # 숫자로 변환해서 저장해주는 필드

    class Meta():
        model = Article
        fields = '__all__'
​```

- 두 serializer의 위치 바꿔줬음
- 결과 : 내용도 볼 수 있음, 댓글개수가 model에는 없지만 serializer를 통해 볼 수 있게 되었음

​```json
{
    "id": 16,
    "comment_set": [
        {
            "id": 6,
            "content": "Economy move issue thus send beautiful turn. Song cell manage positive.",
            "created_at": "1970-08-09T14:32:07Z",
            "article": 16
        }
    ],
    "comment_count": 1,
    "title": "Production focus money.",
    "content": "Television laugh vote something south long red. Just religious wall join open assume thus.",
    "created_at": "1973-01-28T16:26:04Z"
}
​```
```