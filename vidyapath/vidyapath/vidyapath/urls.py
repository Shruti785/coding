"""
URL configuration for vidyapath project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/5.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path,include
from . import views
from .views import notice
from django.conf import settings
from django.conf.urls.static import static
from .views import companies, update_company, delete_company
#from .views import placement_page
# from .views import user_login, user_logout, dashboard


urlpatterns = [
    path('',views.home,name='home'),
    path('admin/', admin.site.urls),
    path('register/', views.register, name='register'),  # URL for register.html
    path('contact/', views.contact, name='contact'),
    path('aboutus/', views.aboutus, name='aboutus'),
    path('adminlogin/', views.adminlogin, name='adminlogin'),
    path('admindashboard/', views.admindashboard, name='admindashboard'),
    path('notice/', views.notice, name='notice'),
    path('notice/update_notice/<int:id>/', views.update_notice, name='update_notice'),
    path('notice/update_notice/update_notice1/<int:id>/', views.update_notice1, name='update_notice1'),
    path("notice/delete/<int:id>/", views.delete, name="delete"),
    path('chatbot/', views.chatbot, name='chatbot'),
    path('placement/', views.placement, name='placement'),
    #path("update_notice/<int:notice_id>/", update_notice, name="update_notice"),
    path('companies/', views.companies, name='companies'),
     path('update_company/<int:company_id>/', update_company, name='update_company'),
    path('delete_company/<int:company_id>/', delete_company, name='delete_company'),
     #path('placement/', include('vidyapath_project.urls')),
    # path('placements/', placement_page, name='placement')
    # path('admin/', admin.site.urls),
   # path('', include('vidyapath_project.urls')),
   # path('login/', user_login, name='login'),
   # path('logout/', user_logout, name='logout'),
    #path('dashboard/', dashboard, name='dashboard'),

] +static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
if settings.DEBUG:
    urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
