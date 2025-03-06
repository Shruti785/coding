from django.shortcuts import render, redirect, get_object_or_404
# from django.http import HttpResponse
# from django.contrib.auth import authenticate, login, logout
from vidyapath_project.models import Registration, Notice, Company
from django.contrib import messages

def home(request):
    all_members = Notice.objects.all()
    return render(request, 'home.html', {'all': all_members})

def contact(request):
    return render(request, 'contact.html')

def aboutus(request):
    return render(request, 'aboutus.html')

def adminlogin(request):
    return render(request, 'adminlogin.html')

def admindashboard(request):
    all_members = Registration.objects.all()
    return render(request, 'admindashboard.html', {'all': all_members})

def notice(request):
    all_members = Notice.objects.all()
    if request.method == "POST":
        description = request.POST["description"]
        notices = Notice(description=description)
        notices.save()
        return redirect('notice')
    return render(request, 'notice.html', {'all': all_members})

def register(request):
    if request.method == 'POST':
        name = request.POST['name']
        batch = request.POST['batch']
        roll_no = request.POST['rollNo']
        smart_card_id = request.POST['smartCardId']
        email = request.POST['email']
        password = request.POST['password']

        # Save data to the database
        new_user = Registration(
            name=name,
            batch=batch,
            rollNo=roll_no,
            smartCardId=smart_card_id,
            email=email,
            password=password
        )
        new_user.save()
        return redirect('home')  # Redirect to the home page after registration

    return render(request, 'register.html')

def update_notice(request, id):
    mem = Notice.objects.get(id=id)
    return render(request, 'update_notice.html', {'mem': mem})

def delete(request, id):
    mem = Notice.objects.get(id=id)
    mem.delete()
    return redirect('notice')

def update_notice1(request, id):
    x = request.POST['description']
    mem = Notice.objects.get(id=id)
    mem.description = x
    mem.save()
    return redirect('notice')

def chatbot(request):
    return render(request, 'chatbot.html')

def placement(request):
    return render(request, 'placement.html')

def companies(request):
    if request.method == "POST":
        name = request.POST['name']
        logo = request.FILES['logo']
        
        # Save company to database
        Company.objects.create(name=name, logo=logo)
        messages.success(request, "Company added successfully!")
        return redirect('companies')

    # Fetch all companies from the database
    all_companies = Company.objects.all()  # Fetching data from MySQL

    return render(request, "companies.html", {"all": all_companies})

def update_company(request, company_id):
    company = get_object_or_404(Company, id=company_id)

    if request.method == "POST":
        company.name = request.POST['name']
        if 'logo' in request.FILES:
            company.logo = request.FILES['logo']
        company.save()
        messages.success(request, "Company updated successfully!")
        return redirect('companies')

    return render(request, "update_company.html", {"company": company})

def delete_company(request, company_id):
    company = get_object_or_404(Company, id=company_id)
    company.delete()
    messages.success(request, "Company deleted successfully!")
    return redirect('companies')

