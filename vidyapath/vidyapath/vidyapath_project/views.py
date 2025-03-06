from django.http import HttpResponse
from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required
from django.contrib import messages
import vidyapath_project.views as views
#from .models import Placement

def home(request):
    return render(request, 'home.html')

def register(request):
    return render(request, 'register.html')

'''def placement_page(request):
    placements = Placement.objects.all()
    return render(request, 'placements.html', {'placements': placements})

def user_login(request):
    if request.GET.get("expired"):
        messages.error(request, "Session expired. Please log in again.")

    if request.method == "POST":
        username = request.POST["username"]
        password = request.POST["password"]
        user = authenticate(request, username=username, password=password)
        if user:
            login(request, user)
            return redirect("admindashboard")
        else:
            messages.error(request, "Invalid username or password")
    
    return render(request, "adminlogin.html")

def user_logout(request):
    logout(request)
    messages.success(request, "You have been logged out successfully.")
    return redirect("user_login")  # Redirect to login page after logout

@login_required
def dashboard(request):
    return render(request, "dashboard.html")'''
